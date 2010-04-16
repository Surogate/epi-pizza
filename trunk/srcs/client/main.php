<?php

require_once 'read.php';
require_once 'init.php';
require_once 'move.php';
require_once 'pars.php';
require_once 'write.php';
require_once 'vision.php';
require_once 'lvl_up.php';
require_once 'display.php';
require_once 'elevation.php';

function main_loop($player)
	{
		$i = 0;
		while (1)
		{
			echo "player send = " . $player['send'] . "\n";
			echo "fd read = " . $read[0] . "\n";
			$read   = array($player['socket']);
			echo "fd read = " . $read[0] . "\n";
			if ($player['send'] != "")
				{
					$write  = array($player['socket']);
					echo "fd write = " . $write[0] . "\n";
				}
			else
				$write  = array();
			$except = NULL;
			$num_changed_sockets = socket_select(&$read, &$write, &$except, 0);
			if ($num_changed_sockets === false) 
				aff_error("Select error : " . socket_strerror(socket_last_error()) . "\n", 0);
			else if ($num_changed_sockets > 0) 
				{
					foreach ($read as $value)
						to_read($value, &$player);
					foreach ($write as $val)
						to_write($val, &$player);
				}
			else
				{
					echo "J'ATTENDS : ";
					echo $num_changed_sockets . "\n";
					/*
					echo "i = " . $i . "\n";
					$i++;
					if ($i == 5)
						{
							$player['send'] = "RETOURNE \n";
						}
					if ($i == 50)
						while (1);
					*/
				}
		}

	}

function connect($ip, $port, $name)
	{
		$tcp = getprotobyname("tcp");
		$s = socket_create(AF_INET, SOCK_STREAM, $tcp);
		$err = socket_connect($s, $ip, $port);
		if ($err == FALSE)
			exit(0);
		else
			echo "Connect on " . $ip . "\n";
		$player = init_player(1, 2, $s, $name);
		main_loop($player);
	}

function connect_serv($argc, $argv)
	{
		$param = array();
		$param = pars_main($argc, $argv);
		connect($param[2], $param[1], $param[0]);
	}
	
connect_serv($argc, $argv);

?>
