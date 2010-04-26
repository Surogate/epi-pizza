<?php

function init_player($sock, $name)
{
	$player = array();
	
	$player['CFbroad'] = 0;
	$player['broad'] = NULL;
	$player['food'] = 10;	
	$player['go_next_lvl'] = 0;
	$player['ans'] = array();
	$player['did'] = array();
	$player['flag'] = 0;
	$player['inv'] = NULL;
	$player['last_receive'] = array();
	$player['level'] = 1;
	$player['objet'] = NULL;
	$player['nb_cmd'] = 0;
	$player['nb_joueur_last'] = -1;
	$player['send'] = array();
	$player['socket'] = $sock;
	$player['team_name'] = $name;
	$player['view'] = NULL;
	$player['next_func'] = 0;
	$player['seeking'] = 0;
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


