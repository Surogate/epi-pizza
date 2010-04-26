<?php

require_once 'move.php';
require_once 'analyse.php';

function analyse(&$player)
{
	to_search(&$player);
	get_there(&$player);
	/*fifo_in(&$player, "prend " . $player['objet'] . "\n");*/
	fifo_in(&$player, "inventaire\n");
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
			$player['view'] = $player['last_receive'][0];
			recv_out(&$player);
		}
	else if (strcasecmp($player['did'][0], "inventaire\n") == 0)
		{
			$player['inv'] = $player['last_receive'][0];
			echo $player['last_receive'][0];
			sleep(3);
			recv_out(&$player);
		}
	if (($player['view'] != NULL) && ($player['inv'] != NULL))
		routine(&$player);
	out_did(&$player);
}

?>
