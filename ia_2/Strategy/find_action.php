<?php

function	food_mode($player)
{
  if ($player["mode"] == FEEDING ||
      $player["mode"] == FEEDING_LEVELING ||
      $player["mode"] == LEVELING)
    {
      if (real_food($player["nourriture"], $player["timer"])
	  < FEEDING_MAX_NOURRITURE)
	$player["mode"] = FEEDING;
      else if (!food_to_level(&$player))
	$player["mode"] = FEEDING_LEVELING;
      else
	$player["mode"] = LEVELING;
    }
}

function	choose_mode($player)
{
  food_mode(&$player);
}

function	find_action($player, $socket)
{
  choose_mode(&$player);
  $player['pmode'][$player["mode"]](&$player, &$socket);
  
}

?>