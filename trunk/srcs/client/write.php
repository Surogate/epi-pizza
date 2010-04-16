<?php

function to_write($socket, &$player)
{
	echo "Je doit envoyer " . $player['send'] . "\n";
	echo "Sur la socket: " . $socket . "\n";
	$sent = socket_send($socket, $player['send'], strlen($player['send']), 0);
	if ($sent != FALSE)
	{
		echo "data sent: " . $player['send'] . "\n";
		$player['send'] = "";
	}
	else
		aff_error("Select error : " . socket_strerror(socket_last_error()) . "\n", 0);
}

?>
