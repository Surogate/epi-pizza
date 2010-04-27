<?php

function	timer_wait($player, $socket, $string)
{
  if ($player['timer_wait'] != -1 &&
      $player['timer'] - $player['timer_wait'] > 328)
    {
      log_ia(&$player, NTIMER, MTIMER_WAIT);
      if ($player['nourriture'] > nb_food_to_level(&$player) * 5)
	$player['mode'] = LEVELING;
      else
	$player['mode'] = FEEDING_LEVELING;
      send_inventaire(&$player);
      $player['timer_wait'] = -1;
    }
}

?>