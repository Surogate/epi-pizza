<?php

function	action_manage($player, $socket, $string)
{
  $tneed = array();

  array_push($tneed, "nourriture");
  if ($player['tmap'])
    create_way(&$player, $socket, $tneed);
  else
    array_push($player["taction"], VOIR);
}

?>