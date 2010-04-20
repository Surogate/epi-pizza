<?php

function fifo_out(&$player)
{
	$x = 1;
	while ($player['send'][$x] != NULL)
	{
		$player['send'][$x - 1]	 = $player['send'][$x];
		$x++;
	}		
}

function fifo_in(&$player, $commande)
{
	$y = 0;
	$len = strlen($commande);
	while ($player['send'][$y] != NULL)
		$y++;
	if ($commande[$len -1] != '\n')
		$commande =  $commande . "\n";
	$player['send'][$y] = $commande;
	
}

?>
