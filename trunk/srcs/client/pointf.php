<?php

require_once 'recv_stack.php';
require_once 'fifo.php';
require_once 'did.php';
require_once 'prio_ulti.php';
require_once 'move.php';
require_once 'analyse.php';

function go_point2(&$player)
{
	echo "**************************************************************************\n";
	echo "GO POINT_2\n";
	echo "**************************************************************************\n";
	if ($player['last_receive'][0] == "ko\n")
		{
			echo "to reach: " . $player['reach'] . "\nobjet: " . $player['objet'] . "\nview: " . $player['view'];
		}
	recv_out(&$player);
	out_did(&$player);
	find_prio(&$player);
}

function go_point(&$player)
{
  echo "**************************************************************************\n";
  echo "GO POINT : did[0]|" . $player['did'][0]. "|\n";
  echo "**************************************************************************\n";
  if (strcasecmp($player['did'][0], "voir\n") == 0)
    {
      $player['view'] = $player['last_receive'][0];
      recv_out(&$player);
      out_did(&$player);
    }
  else if (strcasecmp($player['did'][0], "inventaire\n") == 0)
    {
      $player['inv'] = $player['last_receive'][0];
      recv_out(&$player);
      out_did(&$player);
    }
  if (($player['view'] != NULL) && ($player['inv'] != NULL))
    {
      echo "**************************************************************************\n";
      echo "GO CALL FUNC\n";
      echo "**************************************************************************\n";
      find_prio(&$player);
    }
  echo "Jme casse\n";
}

?>
