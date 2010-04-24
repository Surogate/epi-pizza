<?php

function init_player($sock, $name)
{
	$player = array();
	
	$player['linemate'] = 0;
	$player['deraumere'] = 0;
	$player['sibur'] = 0;
	$player['mendiane'] = 0;
	$player['phiras'] = 0;
	$player['thystame'] = 0;
	
	$player['ans'] = array();
	$player['did'] = array();
	$player['flag'] = 0;
	$player['food'] = 0;
	$player['last_receive'] = "";
	$player['level'] = 1;
	$player['nb_joueur_last'] = -1;
	$player['send'] = array();
	$player['size_x'] = 0;
	$player['size_y'] = 0;
	$player['socket'] = $sock;
	$player['team_name'] = $name;
	$player['ut'] = 1260;
	$player['uv'] = 10;
	
	return ($player);
}

function init_move(&$move, $case)
{
	$move['case_n'] = $case;
	$move['move_forw'] = 0;	
	$move['move_left'] = 0;
	$move['move_right'] = 0;
}

?>	
