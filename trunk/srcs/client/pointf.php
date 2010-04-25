<?php


function analyse(&$player)
{
	echo "faut parser maintenant !!\n";
	sleep(10);
}

function what_seek(&$player)
{
	analyse(&$player);
}

function go_point(&$player)
{
	echo "Nombre de commandes: " . $player['nb_cmd'] . "\n";
	echo "did[0]: " . $player['did'][0];
	if (strcasecmp($player['did'][0], "voir\n") == 0)
		{
			echo "Fill view\n";
			echo "with: " . $player['last_receive'] . "\n";
			$player['view'] = $player['last_receive'];
		}
	else if (strcasecmp($player['did'][0], "inventaire\n") == 0)
		{
			echo "Fill inventaire\n";
			echo "with: " . $player['last_receive'] . "\n";
			$player['inv'] = $player['last_receive'];
			echo "inventaire is: " . $player['inv'] . "\n & view is: " . $player['view'] . "\n";
		}
	if (($player['view'] != NULL) && ($player['inv'] != NULL))
		what_seek(&$player);
	out_did(&$player);
}

?>
