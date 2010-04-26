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
		
  echo "cmd: " . $player['did'][0] . "\n";
  echo "rep: " . $player['last_receive'][0] . "\n";
  while ($i <= 12)
    {
      if (preg_match("/" . $player['did'][0] . "/i", $cmd_tab[$i]) == 1)
	{
	  if (preg_match("/" . $player['last_receive'][0] . "/i", $rep_tab[$i]) == 1)
	    {
	      go_point(&$player);
	      return (0);
	    }
	  else if ($player['last_receive'][0][0] == '{')
	    {
	      go_point(&$player);
	      return (0);
	    }
	  else
	    {
	      echo "rep: " . $player['last_receive'][0] . "\n";
	      echo "pif\n";
	      while (1);
	      return (-1);
	    }
	}
      else
	$i++;
      echo "i = " . $i . "\n";
    }
  while (1);
}

?>
