<?php

require_once 'command_serv.php';

function find_null(&$player)
{
	$j = 0;
	while ($player['ans'][$j] != NULL)
		$j++;
	return ($j);
}
function which_ans(&$player)
{
	global $cmd_tab;
	global $rep_tab;
	$i = find_null(&$player);
	
	while ($i <= 12)
	{
		if (strcasecmp($player['did'][0], $cmd_tab[$i]) == 0)
			{
				if (strcasecmp($player['ans'][0], $rep_tab[$i]) == 0)
					go_pointf(&$player)
			}
		else if (preg_match("/" . $player['did'][0] . "/i", $cmd_tab[$i]) == 1)
		{
			if (preg_match($player['ans'][0], $rep_tab[$i]) == 1)
					go_pointf(&$player);
		}
			$player['ans'] = $rep_tab[$i];
		else
			$i++;
	}
}

function compare_ans()

?>
