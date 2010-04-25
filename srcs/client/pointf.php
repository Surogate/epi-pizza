<?php


function analyse(&$player)
{
	echo "faut parser maintenant !!\n";
	while (1);
}

function what_seek(&$player)
{
	analyse(&$player);
}

function go_point(&$player)
{
	echo "Nombre de commandes: " . $player['nb_cmd'] . "\n";
	echo "did[0]: " . $player['did'][0];
	sleep(2);
	if (strcasecmp($player['did'][0], "voir\n") == 0)
		{
			echo "Fill view\n";
			echo "with: " . $player['last_receive'][0] . "\n";
			$player['view'] = $player['last_receive'][0];
			recv_out(&$player);
		}
	else if (strcasecmp($player['did'][0], "inventaire\n") == 0)
		{
			echo "Fill inventaire\n";
			echo "with: " . $player['last_receive'][0] . "\n";
			$player['inv'] = $player['last_receive'][0];
			echo "inventaire is: " . $player['inv'] . "\n & view is: " . $player['view'] . "\n";
			recv_out(&$player);
		}
	if (($player['view'] != NULL) && ($player['inv'] != NULL))
		what_seek(&$player);
	out_did(&$player);
}

?>
