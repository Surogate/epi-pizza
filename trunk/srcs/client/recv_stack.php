<?php

function put_in(&$player, $com)
{
  $y = 0;
  while ($player['last_receive'][$y] != NULL)
    $y++;
  $player['last_receive'][$y] = $com;
}

function recv_out(&$player)
{
  $player['last_receive'][0] = NULL;
  $x = 1;
  while ($player['last_receive'][$x] != NULL)
    {
      $player['last_receive'][$x - 1]	 = $player['last_receive'][$x];
      $x++;
    }
  $player['last_receive'][$x - 1] = NULL;		
}

function recv_in(&$player, $commande)
{
  $tab = array();
  $z = 0;
  if ($playe['nb_cmd'] > 1)
    {
      $tab = explode("\n", $commande);
      while ($player['nb_cmd'] != 0)
	{
	  put_in(&$player, $tab[$z]);
	  $player['nb_cmd']--;
	  $z++;
	}
    }
  else
    put_in(&$player, $commande);
}
?>
