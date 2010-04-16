<?php

require_once 'manage.php';

function to_read($socket, &$player)
{
	echo "read : " . $socket . "\n";
	socket_recv($socket, $buff, 4096, 0);
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
	echo "Received data : " . $buff . "\n";
	manage($buff, &$player);
}

?>
