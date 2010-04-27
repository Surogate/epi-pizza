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
	  else if ((preg_match("/" . $rep_tab[$i] . "/i", $player['last_receive'][0]) == 1) || (preg_match("/" . $rep_tab[$i + 10] . "/i", $player['last_receive'][0]) == 1))
	    {
	      go_point2(&$player);
	      return (0);
	    }
	}
      else
	$i++;
    }
}

?>
