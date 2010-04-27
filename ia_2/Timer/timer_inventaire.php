<?php

function	timer_inventaire($player, $socket, $string)
{
  static	$i = 0;

  if ($player["time_inv"] == -1)
    $player["timer_inv"] =  $player["timer"];

  if ($player["timer"] - $player["time_inv"] > DELAY_INVENTAIRE)
    {
      if ($player['mode'] != FEEDING &&
	  $player['mode'] != SPAMMING &&
	  $player['mode'] != SINCRUSTING &&
	  $player['mode'] != MANAGING)
	$i++;
      array_push($player['taction'], INVENTAIRE);
      $player["time_inv"] = $player["timer"];
      if ($i == 5)
	{
	  log_ia(&$player, NTIMER, MTIMER_INVENTORY);
	  send_inventaire(&$player);
	  $i = 0;
	}
    }
}

?>