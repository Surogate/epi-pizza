<?php

require_once 'manage.php';

function debug($buff)
{
	if (strcmp($buff, "KO\n") == 0)
		{
			echo "STOP KO";
			while (1);
		}
		if (strcmp($buff, "OK\n") == 0)
		{
			echo "STOP OK";
			while (1);
		}	
}

function to_read($socket, &$player)
{
	echo "read : " . $socket . "\n";
	socket_recv($socket, $buff, 4096, 0);
	echo "Received data : " . $buff . "\n";
	$player['last_receive'] = $buff;
	manage($buff, &$player);
}
?>
