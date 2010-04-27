<?php

function	action_ponding($player, $socket, $string)
{
  for ($i = 0; $i < $player['negg']; $i++)
    array_push($player['taction'], FORK);
  $player['negg'] = 0;  
  $tneed = array();
  array_push($tneed, "nourriture");
  if ($player['tmap'])
    create_way(&$player, $socket, $tneed);
  else
    array_push($player["taction"], VOIR);
}

?>