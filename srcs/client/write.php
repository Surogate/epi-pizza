<?php

function to_write($socket, &$player)
{
	$sent = socket_send($socket, $player['send'][0], strlen($player['send'][0]), 0);
	if ($sent != FALSE)
	{
		echo "**************************************************************************\n";
		echo "data sent: |" . $player['send'][0] . "|";
		echo "**************************************************************************\n";
		if (strcasecmp($player['send'][0], $player['team_name'] . "\n") != 0)
			in_did(&$player, $player['send'][0]);
		fifo_out(&$player);
	}
	else
		aff_error("Select error : " . socket_strerror(socket_last_error()) . "\n", 0);
}

?>
