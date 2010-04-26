<?php

require_once 'manage.php';
require_once 'recv_stack.php';

function to_read($socket, &$player)
{
	$rec = socket_recv($socket, $buff, 4096, 0);
	if ($rec != FALSE)
		{
			echo "**************************************************************************\n";
			echo "Received data : " . $buff . "\n";
			echo "**************************************************************************\n";
			str_replace("\n", "\n", $buff, $counter);
			$player['nb_cmd'] = $counter;
			recv_in(&$player, $buff);
			if (preg_match("/mort/i", $buff/*$player['last_receive'][0]*/) == 1)
				exit("Vous etes mort\n");
			manage(&$player);
		}
	else
		aff_error("Select error : " . socket_strerror(socket_last_error()) . "\n", 0);
}
?>
