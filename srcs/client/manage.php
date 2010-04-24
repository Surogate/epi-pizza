<?php

require_once 'str_func.php';
require_once 'loop_manage.php';

function init_conv(&$player)
{
	fifo_in(&$player, $player['team_name'] . "\n");
	$player['flag'] = 1;
}

function get_int(&$player)
{
	$size = array();
	$cmd_serv = str_replace("\n", " ", $player['last_receive']);
	$size = explode(" ", $player['last_receive']);
	$player['nb_joueur_last'] = intval($size[0]);
	$player['size_x'] = intval($size[1]);
	$player['size_y'] = intval($size[2]);
	$player['flag'] = 2;
	fifo_in(&$player, "voir\n");
}

function manage(&$player)
{
	echo "Dans manage avec la commande: " . $player['last_receive'] . "\n";
	if (strcasecmp($player['last_receive'], "bienvenue\n") == 0)
		init_conv(&$player);
	else if ($player['flag'] == 1)
		get_int(&$player, );
	else if ($player['flag'] == 2)
		loop_manage(&$player);
	else
		aff_error("Initial talk with server failed \n", 0);
}
?>
