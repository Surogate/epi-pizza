<?php

function	action_casting($player, $socket, $string)
{
  $msg = create_msg(&$player, START_INCANT);
  array_push($player['taction'], $msg);

  array_push($player['taction'], INCANTATION);
  
  log_ia(&$player, NLEVEL, MLEVEL_INCANT);
  if ($player['nourriture'] > nb_food_to_level(&$player) * 5)
    $player['mode'] = LEVELING;
  else
    $player['mode'] = FEEDING_LEVELING;
  log_ia(&$player, NMODE, MMODE_CHANGE . $player['mode']);
  $player['bcast'] = true;
}

?>