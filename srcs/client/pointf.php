<?php

require_once 'recv_stack.php';
require_once 'fifo.php';
require_once 'did.php';
require_once 'prio_ulti.php';
require_once 'move.php';
require_once 'analyse.php';

function go_point2(&$player)
{
  if ($player['did'][0] == "incantation\n")
    {
      if ($player['last_receive'][0] == "elevation en cours\n")
	{
	  echo "incantation: " . $player['last_receive'][0] . "\n";
	  recv_out(&$player);
	  return (0);
	}
      else
	{
	  echo "incantation: " . $player['last_receive'][0] . "\n";
	  recv_out(&$player);
	  out_did(&$player);
	  $player['level'] += 1;
	  fifo_in(&$player, "fork\n");
	  return (0);
	  
	}
    }
  if ($player['did'][0] == "fork\n")
    echo "rep fork: " . $player['last_receive'][0] . "\n";
  if ($player['last_receive'][0] == "ko\n")
    echo "to reach: " . $player['reach'] . "\nobjet: " . $player['objet'] . "\nview: " . $player['view'];
  recv_out(&$player);
  out_did(&$player);
 }

function go_point(&$player)
{
  echo "player did: " . $player['did'][0] . "\n";
  echo "player did: " . $player['did'][1] . "\n";
  echo "player receive: " . $player['last_receive'][0] . "\n";
  echo "player receive: " . $player['last_receive'][1] . "\n";
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
    find_prio(&$player);
}

?>
