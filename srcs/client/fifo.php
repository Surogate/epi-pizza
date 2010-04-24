<?php

function fifo_out(&$player)
{
	echo "cmd: " . $player['send'][0];
	$player['send'][0] = NULL;
	echo "cmd_erased: " . $player['send'][0] . "\n";
	
	$x = 1;
	while ($player['send'][$x] != NULL)
		{
			$player['send'][$x - 1]	 = $player['send'][$x];
			$x++;
		} 
	$player['send'][$x - 1] = NULL;
	echo "cmd: " . $player['send'][0] . "\n";
	sleep(2);
}

function fifo_in(&$player, $commande)
{
	$y = 0;
	$len = strlen($commande);
	while ($player['send'][$y] != NULL)
		$y++;
	$player['send'][$y] = $commande;
}

?>
