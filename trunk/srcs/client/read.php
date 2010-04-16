<?php

require_once 'manage.php';

function to_read($socket, &$player)
{
	echo "read : " . $socket . "\n";
	socket_recv($socket, $buff, 4096, 0);
	echo "Received data : " . $buff . "\n";
	manage($buff, &$player);
}

?>
