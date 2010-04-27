<?php

function	action_feedingl($player, $socket, $string)
{
  $tneed = array();

  if ($player['tmap'])
    {
      foreach ($player['glevel'][$player['level']] as $key => $val)
        {
          if ($player[$key] < $val && $key != 'joueur')
            array_push($tneed, $key);
        }
      array_push($tneed, "nourriture");
      create_way(&$player, $socket, $tneed);
    }
  else
    array_push($player["taction"], VOIR);

  if (!food_to_level(&$player))
    {
      log_ia(&$player, NMODE, MMODE_CHANGE . FEEDING);
      $player['mode'] = FEEDING;
    }
  if ($player['nourriture'] > nb_food_to_level(&$player) * 5)
    {
      log_ia(&$player, NMODE, MMODE_CHANGE . LEVELING);
      $player['mode'] = LEVELING;
    }
}

?>