<?php

require_once 'answer.php';
require_once 'str_func.php';
require_once 'loop_manage.php';

function init_conv(&$player)
{
	fifo_in(&$player, $player['team_name'] . "\n");
	$player['flag'] = 1;
	recv_out(&$player);
}

function get_int(&$player)
{
	$cmd_serv = str_replace("\n", "", $player['last_receive'][0]);
	$player['nb_joueur_last'] = intval($player['last_receive'][0]);
	$player['flag'] = 2;
	recv_out(&$player);
}

function get_size(&$player)
{
	$size = array();
	$player['last_receive'][0] = str_replace("\n", "", $player['last_receive'][0]);
	$size = explode(" ", $player['last_receive'][0]);
	$player['size_x'] = intval($size[0]);
	$player['size_y'] = intval($size[1]);
	$player['flag'] = 3;
	recv_out(&$player);
	fifo_in(&$player, "voir\n");
	fifo_in(&$player, "inventaire\n");
}

function manage(&$player)
{
	if (strcasecmp("mort\n", $player['last_receive'][0]) == 0)
		exit ("Vous etes mort\n");
	if (strcasecmp($player['last_receive'][0], "bienvenue\n") == 0)
		init_conv(&$player);
	else if ($player['flag'] == 1)
		get_int(&$player);
	else if ($player['flag'] == 2)
		get_size(&$player);
	else if ($player['flag'] == 3)
		which_ans(&$player);
	else
		aff_error("Initial talk with server failed \n", 0);
	echo "manage\n";
}
?>
