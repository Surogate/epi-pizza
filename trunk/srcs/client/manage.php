<?php

require_once 'vision.php';
require_once 'loop_manage.php';

function init_conv(&$player)
{
	echo "init_conv: ";
	$player['send'] =$player['team_name'] . "\n";
	$player['flag'] = 1;
	echo "NAME: " . $player['send'] . "\n";
}

function get_int(&$player, $cmd_serv)
{
	$size = array();
	echo "get_player: ";
	$cmd_serv = str_replace("\n", " ", $cmd_serv);
	$size = explode(" ", $cmd_serv);
	$player['nb_joueur_last'] = intval($size[0]);
	$player['size_x'] = intval($size[1]);
	$player['size_y'] = intval($size[2]);
	$player['flag'] = 2;
	echo "NB_PLAYER_LAST = " . $player['nb_joueur_last'] . "\n";
	echo "Mais c'est tip top sa !!! \n";
	aff("size_x = ", $player['size_x']);
	aff("size_y = ", $player['size_y']);
	aff("reste tant de joueur possible = ", $player['nb_joueur_last']);
	while (1);
}

function manage($cmd_serv, &$player)
{
	clean(&$cmd_serv);
	echo "Dans manage avec la commande: " . $cmd_serv . "\n";
	if (strcasecmp($cmd_serv, "bienvenue ") == 0)
		init_conv(&$player);
	else if ($player['flag'] == 1)
		get_int(&$player, $cmd_serv);
	else if ($player['flag'] == 2)
		loop_manage($cmd_serv, &$player);
	else
		aff_error("Initial talk with server failed \n", 0);
	
}
?>
