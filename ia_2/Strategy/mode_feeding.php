<?php

function        mode_feeding($player, $socket)
{
  $tneed = array();

  array_push($tneed, "nourriture");
  if ($player['voir'] == true)
    create_way(&$player, $socket, $tneed);
  else
    array_push($player["action"], VOIR);
}

?>
