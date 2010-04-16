<?php

function init_player($x, $y, $sock, $name)
{
	$player = array();
	$player['nb_joueur_last'] = -1;
	$player['team_name'] = $name;
	$player['linemate'] = 0;
	$player['deraumere'] = 0;
	$player['sibur'] = 0;
	$player['mendiane'] = 0;
	$player['phiras'] = 0;
	$player['thystame'] = 0;
	$player['level'] = 1;
	$player['food'] = 0;
	$player['pos_x'] = $x;
	$player['pos_y'] = $y;
	$player['size_x'] = 0;
	$player['size_y'] = 0;
	$player['socket'] = $sock;
	$player['send'] = "";
	$player['flag'] = 0;
	return ($player);
}

function init_vision(&$vision)
{
	
}

?>	
