<?php

function	std_actuallevel($player, $socket, $level)
{
  $player['level'] = $level;

  log_ia(&$player, NLEVEL, MLEVEL_NEW . "$level");
  send_inventaire(&$player);

  if ($player['bcast'] == true)
    {
      array_shift($player['tresolve']);
      $player['bcast'] = false;
    }
  if ($player['nourriture'] > nb_food_to_level(&$player) * 5)
    $player['mode'] = LEVELING;
  else
    $player['mode'] = FEEDING_LEVELING;
  $player['timer_wait'] = -1;
}

?>