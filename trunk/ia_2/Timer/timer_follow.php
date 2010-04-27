<?php

function	timer_follow($player, $socket, $string)
{
  if ($player["timer_follow"] == -1)
    $player["timer_follow"] = $player["timer"];

  if ($player["timer"] - $player["timer_follow"]
      > (nb_food_to_level(&$player) * 126))
    {
      log_ia(&$player, NTIMER, MTIMER_FOLLOW);
      $player['mode'] = FEEDING;
      $player["timer_follow"] = -1;
    }
}

?>