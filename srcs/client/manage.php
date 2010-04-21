<?php

require_once 'str_func.php';
require_once 'loop_manage.php';

function init_conv(&$player)
{
	fifo_in(&$player, $player['team_name'] . "\n");
	$player['flag'] = 1;
}

function get_int(&$player, $cmd_serv)
{
	$size = array();
	$cmd_serv = str_replace("\n", " ", $cmd_serv);
	$size = explode(" ", $cmd_serv);
	$player['nb_joueur_last'] = intval($size[0]);
	$player['size_x'] = intval($size[1]);
	$player['size_y'] = intval($size[2]);
	$player['flag'] = 2;
	fifo_in(&$player, "voir\n");
}

function manage($cmd_serv, &$player)
{
	echo "Dans manage avec la commande: " . $cmd_serv . "\n";
	if (strcasecmp($cmd_serv, "bienvenue\n") == 0)
		init_conv(&$player);
	else if ($player['flag'] == 1)
		get_int(&$player, $cmd_serv);
	else if ($player['flag'] == 2)
		loop_manage($cmd_serv, &$player);
	else
		aff_error("Initial talk with server failed \n", 0);
}
?>
