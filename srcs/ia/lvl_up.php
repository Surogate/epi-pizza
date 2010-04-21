<?php

include 'elevation.php';

function is_stone($pierre, $next_l)
{
	global $lvl;
	
	if ($player[$pierre] >= $lvl[$next_l][$pierre])
		return (1);
	else
		return (0);
}

function check_stone($player, $next_l)
{
	$state = is_stone('linemate', $next_l);
	if ($state == 1)
		$state = is_stone('deraumere', $next_l);
	if ($state == 1)
		$state = is_stone('sibur', $next_l);
	if ($state == 1)
		$state = is_stone('mendiane', $next_l);
	if ($state == 1)
		$state = is_stone('phiras', $next_l);
	if ($state == 1)
		$state = is_stone('thystame', $next_l);
	if ($state == 1)
		return (1);
	else
		return (0);
}

function enough_p($search_lvl)
{
	$nb_find = 1;
	return ($nb_find);
}

function lvl_up($player)
{
	global $lvl;
	
	$next_l = $player['level'] + 1;
	$up_player = enough_p($player['level']);
	if ($lvl[$next_l]['nb_player'] == $up_player)
		{
			$go_lvl = check_stone($player, $next_l);
			if ($go_lvl == 1)
				go_incante(&$player);
			else
				return ($player);
		}
	return ($player);
}

?>
