<?php

function get_way($parse_broad)
{
	$size = strlen($parse_broad[0]);
	$sound_direction = $parse_broad[0][$size - 1];
	$sound_direction = intval($sound_direction);
	return ($sound_direction);
}

function broad_send(&$player, $missive)
{
	$to_broad = "broadcast " . $missive;
	fifo_in(&$player, $to_broad);
}

function broad_recv(&$player, $text)
{
	$parse_broad = array();
	$parse_broad = explode(",", $text);
	$sound_way = get_way($parse_broad);
	while (1);
}
?>
