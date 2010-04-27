<?php

function	timer_manage($player, $socket, $string)
{
  if ($player["timer_manage"] == -1)
    $player["timer_manage"] = $player['timer'];

  if ($player['bmanage'] == false &&
      $player['timer'] - $player['timer_manage'] > DELAY_MANAGE)
    {
      log_ia(&$player, NTIMER, MTIMER_MANAGE);
      if ($player['pid'] == $player['min_pid'])
	{
	  $player['mode'] = MANAGING;
	}
      $player['bmanage'] = true;
    }
}

?>