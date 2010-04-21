<?php

function go_to(&$player, &$move)
{
	while ($move['move_forw'] != 0)
		{
			fifo_in(&$player, "avance\n");
			$move['move_forw']--;
		}
	while ($move['move_right'] != 0)
		{
			fifo_in(&$player, "droite\n");
			$move['move_right']--;
		}
	while ($move['move_left'] != 0)
		{
			fifo_in(&$player, "gauche\n");
			$move['move_left']--;
		}
}

function coord(&$move, $get_pos, &$player, $niv)
{	
	$move['move_forw'] = $niv;
	if ($move['case_n'] < $get_pos)
		$move['move_left'] = $get_pos - $move['case_n'];
	else if ($move['case_n'] > $get_pos)
		$move['move_right'] = $move['case_n'] - $get_pos;
	return (1);
}
	
function get_pos($lvl)	
{
	$pos = 0;
	$decal = 2;
	$i = 0;
	While ($i != $lvl)
	{
		$pos += $decal;
		$decal += 2;
		$i++;
	}
	return ($pos);
}
	
function get_there($case_num, &$player)
{
	$move = array();
	init_move(&$move, $case_num);
	
	if ($case_num != 0)
	{
		$end = 0;
		$niv = 1;
		while (($niv <= $player['level']) && ($end != 1))
		{
			$get_pos = pos_max($niv);
			if (($case_num >= ($get_pos - $niv)) && (($case_num) <= $get_pos + $niv))
				$end = coord(&$move, $get_pos, &$player, $niv);
			else
				$niv++;
		}
		go_to(&$player, &$move);
	}
	else
		return (0);
	
	
}
	
?>
