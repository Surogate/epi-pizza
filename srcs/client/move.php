<?php

require_once 'fifo.php';

function go_to(&$player, &$move)
{
	while ($move['move_forw'] != 0)
		{
			fifo_in(&$player, "avance\n");
			$move['move_forw']--;
		}
	if ($move['move_right'] != 0)
		{
			fifo_in(&$player, "droite\n");
			$move['move_right'] = 0;
		}
	if ($move['move_left'] != 0)
		{
			fifo_in(&$player, "gauche\n");
			$move['move_left'] = 0;
		}
}

function coord(&$move, $pos, &$player, $niv)
{	
	$move['move_forw'] = $niv;
	go_to(&$player, &$move);
	if ($move['case_n'] < $pos)
		{
			$move['move_left'] = 1;
			go_to(&$player, &$move);
			$move['move_forw'] = ($pos - $move['case_n']);
			go_to(&$player, &$move);
		}
	else if ($move['case_n'] > $pos)
		{
			$move['move_right'] = 1;
			go_to(&$player, &$move);
			$move['move_forw'] = ($move['case_n'] - $pos);
			go_to(&$player, &$move);
		}
	return (1);
}
	
function pos_max($lvl)	
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
	
function get_there(&$player)
{
	$move = array();
	echo "**************************************************************************\n";
	echo "Move : " . $player['reach'] . "\n";
	echo "**************************************************************************\n";
	init_move(&$move, $player['reach']);
	echo "Checkpoint0\n";
	if ($move['case_n'] != 0)
	{
		echo "Checkpoint1\n";
		$end = 0;
		$niv = 1;
		while (($niv <= $player['level']) && ($end != 1))
		{
			echo "Checkpoint2\n";
			$pos = pos_max($niv);
			if (($player['reach'] >= ($pos - $niv)) && (($player['reach']) <= $pos + $niv))
				$end = coord(&$move, $pos, &$player, $niv);
			else
				$niv++;
		}
		echo "Checkpoint3\n";
	}
	else
		return (0);
	
	
}
	
?>
