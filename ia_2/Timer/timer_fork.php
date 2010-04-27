<?php

function	timer_fork($player, $socket, $string)
{
  if ($player['timer'] > DELAY_FORK
      && $player['bfork'] == true 
      && $player['param']['fork'] != 'off')
    {
      $player['bfork'] = false;
      if ($player['nally'] < 10 && $player['pid'] == $player["min_pid"])
	{
	  log_ia(&$player, NTIMER, MTIMER_FORK1);
	  for ($i = 0; $i < (int)(10 - $player['nally']); $i++)
	    array_push($player['taction'], FORK);
	  return ;
	}
    }

  foreach ($player["ttime_fork"] as $key => $val)
    {
      if ($player["timer"] - $val > 600)
	{
	  log_ia(&$player, NTIMER, MTIMER_FORK2);
	  array_unshift($player["taction"], CONNECT_NBR);
	  unset($player["ttime_fork"][$key]);
	}
    }
}

?>