<?php

function to_write($socket, &$player)
{
	echo "Je doit envoyer " . $player['send'][0] . "\n";
	echo "Sur la socket: " . $socket . "\n";
	$sent = socket_send($socket, $player['send'][0], strlen($player['send'][0]), 0);
	if ($sent != FALSE)
	{
		echo "data sent: " . $player['send'][0] . "\n";
		/*which_ans(&$player, $player['send'][0]);*/
		in_did(&$player, $player['send'][0]);
		fifo_out(&$player);
	}
	else
		aff_error("Select error : " . socket_strerror(socket_last_error()) . "\n", 0);
}

?>
