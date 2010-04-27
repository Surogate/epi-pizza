<?php

function        action_feeding($player, $socket, $string)
{
  $tneed = array();

  array_push($tneed, "nourriture");
  if ($player['tmap'])
    create_way(&$player, $socket, $tneed);
  else
    array_push($player["taction"], VOIR);

  if (food_to_level(&$player))
    {
      log_ia(&$player, NMODE, MMODE_CHANGE . FEEDING_LEVELING);
      $player['mode'] = FEEDING_LEVELING;
    }
}

?>