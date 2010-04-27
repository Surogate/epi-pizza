<?php

function	std_fork($player, $socket, $string)
{
  array_shift($player["tresolve"]);

  if ((int)$string > 0)
    {
      if (($player['nfork'] - 1) == -1)
	return ;
      $player['nfork'] -= 1;

      if (!pcntl_fork())
	{
	  socket_close($socket);
	  $socket = init_connect(&$player);
	  init_player(&$player);
	  init_level(&$player);
	  init_mode(&$player);
	  init_ia(&$player, $socket);
	  $nb = rand() % RANG_FORK;
	  for ($i = 0; $i < $nb; $i++)
	    array_push($player['taction'], AVANCE);
	}
      else
	return ;
    }
}

?>