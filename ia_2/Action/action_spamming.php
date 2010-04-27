<?php

function	action_spamming($player, $socket, $string)
{
  static	$food = false;

  if ($player['nourriture'] > (nb_food_to_level(&$player) * 2))
    $food = true;
  if ($player['nourriture'] < nb_food_to_level(&$player))
    $food = false;

  if ($food == false)
    {
      $tneed = array();
      
      array_push($tneed, "nourriture");
      if ($player['tmap'])
	create_way(&$player, $socket, $tneed);
      else
	array_push($player["taction"], VOIR);
    }
  $msg = "broadcast " . $player['spam'] . "\n";
  array_push($player['taction'], $msg);
}

?>