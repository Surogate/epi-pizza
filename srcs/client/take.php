<?php

function take(&$player, $objet)
{
	$len = strlen($objet);
	if ($objet[$len - 1] != '\n')
		$commande = "prendre " . $objet . "\n";
	else
		$commande = "prendre " . $objet;
	fifo_in(&$player, $commande);
}

?>
