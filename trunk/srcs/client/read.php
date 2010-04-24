<?php

require_once 'manage.php';

function to_read($socket, &$player)
{
	socket_recv($socket, $buff, 4096, 0);
	echo "Received data : " . $buff . "\n";
	$player['last_receive'] = $buff;
	str_replace("\n", "\n", $buff, $counter);
	$player['nb_cmd'] = $counter;
	manage(&$player);
}
?>
