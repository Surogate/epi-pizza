<?php

function out_did(&$player)
{
	$x = 1;
	while ($player['did'][$x] != NULL)
	{
		$player['did'][$x - 1]	 = $player['did'][$x];
		$x++;
	}		
}

function in_did(&$player, $commande)
{
	$y = 0;
	$len = strlen($commande);
	while ($player['did'][$y] != NULL)
		$y++;
	if ($commande[$len -1] != '\n')
		$commande =  $commande . "\n";
	$player['did'][$y] = $commande;
}

?>
