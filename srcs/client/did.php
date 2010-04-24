<?php

function out_did(&$player)
{
	echo "out_did\n";
	$player['did'][0] = NULL;
	$x = 1;
	while ($player['did'][$x] != NULL)
	{
		$player['did'][$x - 1]	 = $player['did'][$x];
		$x++;
	}
	$player['did'][$x - 1] = NULL;		
}

function in_did(&$player, $commande)
{
	$y = 0;
	$len = strlen($commande);
	while ($player['did'][$y] != NULL)
		$y++;
	$player['did'][$y] = $commande;
}

?>
