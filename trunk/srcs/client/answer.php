<?php

require_once 'command_serv.php';
require_once 'pointf.php';

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
  $i = 0;

  while ($i <= 12)
    {
      if (preg_match("/" . $cmd_tab[$i] . "/i", $player['did'][0]) == 1)
		{
		  echo "//////////////////////////////////////////////////////////////////////\n";
		  echo "last receive [0] [0] |" . $player['last_receive'][0][0] . "|\n";
		  echo "last receive |" . $player['last_receive'][0] . "|\n";
		  echo "//////////////////////////////////////////////////////////////////////\n";
		  if ($player['last_receive'][0][0] === '{')
			{
			  go_point(&$player);
			  return (0);
			}
		  else if ((preg_match("/" . $player['last_receive'][0] . "/i", $rep_tab[$i]) == 1) || (preg_match("/" . $player['last_receive'][0] . "/i", $rep_tab[$i + 10]) == 1))
			{
			  go_point2(&$player);
			  return (0);
			}
		  else
			{
			  echo "rep: " . $player['last_receive'][0] . "\n";
			  echo "pif\n";
			  return (-1);
			}
		}
      else
	$i++;
      echo "i = " . $i . "\n";
    }
}

?>
