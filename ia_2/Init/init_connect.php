<?php

declare(ticks = 1);

function	init_connect($player)
{
  $rsp = "";
  $tab = array();

  $socket = @socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
  if ($socket == false)
    ia_die(SCREATE_ERR);
  if (@socket_connect($socket, $player['param']['h'],
		      (int)$player['param']['p']) == false)
    ia_die(SCONNECT_ERR);
  if (false == ($rsp = @socket_read($socket, BUFF_SIZE, PHP_NORMAL_READ)))
    ia_die(SREAD_ERR);

  if (strcmp($rsp, CONNECT_SUCCESS) == 0)
    {
      if (@socket_write($socket, $player['param']['t'] . "\n") == false)
	ia_die(SWRITE_ERR);
      if (false == ($rsp = @socket_read($socket, BUFF_SIZE, PHP_NORMAL_READ)))
	ia_die(SREAD_ERR);
      if (strcmp($rsp, CLIENT_ACCEPT))
	{
	  $player["id"] = (int)$rsp;
	  if (false == ($rsp = @socket_read($socket, BUFF_SIZE)))
	    ia_die(SREAD_ERR);
	  $tab = explode(" ", $rsp);
	  $player["wmap"] = (int)$tab[0];
	  $player["hmap"] = (int)$tab[1];
	  pcntl_signal(SIGINT, 'client_quit');
	  pcntl_signal(SIGCHLD, 'client_wait');
	  log_ia(&$player, NCONNECT, MCONNECT_SUCCESS);
	  return ($socket);
	}
      else
	echo CLIENT_REFUSE;
    }
  else
    echo CONNECT_FAILURE;
  exit ;
}

function        client_quit($sig)
{
  global $socket;

  echo "Quit\n";
  exit ;
}

function        client_wait($sig)
{
  $status = 0;

  pcntl_wait(&$status);
  return ;
}

?>