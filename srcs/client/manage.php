<?php

require_once 'vision.php';
require_once 'loop_manage.php';

function init_conv(&$player)
{
	echo "init_conv: ";
	$maj_name = strtoupper($player['team_name']);
	$player['send'] = $maj_name;
	$player['flag'] = 1;
	echo "NAME: " . $player['send'] . "\n";
}

function get_player(&$player, $cmd_serv)
{
	echo "get_player: ";
	$player['nb_joueur_last'] = intval($cmd_serv);
	$player['flag'] = 2;
	echo "NB_PLAYER_LAST = " . $player['nb_joueur_last'] . "\n";
	while (1);
}

function get_map_size(&$player, $cmd_serv)
{
	$size = array();
	$size = explode(" ", $cmd_serv);
	$player['size_x'] = $size[0];
	$player['size_y'] = $size[1];
	$player['flag'] = 3;
	while (1);
}

function manage($cmd_serv, &$player)
{
	clean(&$cmd_serv);
	echo "Dans manage avec la commande: " . $cmd_serv . "\n";
	if (strcasecmp($cmd_serv, "bienvenue") == 0)
		init_conv(&$player);
	else if ($player['flag'] == 1)
		get_player(&$player, $cmd_serv);
	else if ($player['flag'] == 2)
		get_map_size(&$player, $cmd_serv);
	else if ($player['flag'] == 3)
		loop_manage($cmd_serv, &$player);
	else
		aff_error("Initial talk with server failed \n", 0);
	
}
?>
