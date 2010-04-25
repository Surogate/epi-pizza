<?php

require_once 'manage.php';
require_once 'recv_stack.php';

function to_read($socket, &$player)
{
	$rec = socket_recv($socket, $buff, 4096, 0);
	if ($rec != FALSE)
		{
			echo "Received data : " . $buff . "\n";
			str_replace("\n", "\n", $buff, $counter);
			$player['nb_cmd'] = $counter;
			recv_in(&$player, $buff);
			manage(&$player);
		}
	else
		aff_error("Select error : " . socket_strerror(socket_last_error()) . "\n", 0);
}
?>
