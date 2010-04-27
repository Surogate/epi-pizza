<?php

function fifo_out(&$player)
{
  $x = 1;
  $player['send'][0] = NULL;
  while ($player['send'][$x] != NULL)
    {
      $player['send'][$x - 1]	 = $player['send'][$x];
      $x++;
    } 
  $player['send'][$x - 1] = NULL;
}

function fifo_in(&$player, $commande)
{
  $y = 0;
  $len = strlen($commande);
  while ($player['send'][$y] != NULL)
    $y++;
  $player['send'][$y] = $commande;
}

?>
