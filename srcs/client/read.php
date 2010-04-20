<?php

require_once 'manage.php';

function to_read($socket, &$player)
{
	echo "read : " . $socket . "\n";
	socket_recv($socket, $buff, 4096, 0);
	echo "Received data : " . $buff . "\n";
	/*
	if ($buff[0] == '{')
		{
			echo "cmd clean \n";
			while (1);
		}
	*/
	$player['last_receive'] = $buff;
	manage($buff, &$player);
	echo "i'm back \n";
}

	/*
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
	*/
?>
