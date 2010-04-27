<?php

function	gere_fork($player, $socket, $string)
{
  array_shift($player["naction"]);
  if ((int)$string > 0)
    {
      if (!pcntl_fork())
	{
	  socket_close($socket);
	  $param = $player['param'];
	  $player = init_player($param);
	  init_level(&$player);
	  init_mode(&$player);
	  init_message(&$player);
	  $socket = init_connect($param['h'], (int)$param['p'], $param['t'], &$player);
	  init_ia(&$player, $socket);
	}
      else
	return ;
    }
  else
    $player["time_fork"] = $player["time"] - (600 - DELAY_FORK);
}

?>