<?php

function take(&$player, $objet)
{
	$len = strlen($objet);
	if ($objet[$len - 1] != '\n')
		$commande = "prend " . $objet . "\n";
	else
		$commande = "prend " . $objet;
	fifo_in(&$player, $commande);
}

?>
