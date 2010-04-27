<?php

function	apply_ia($player, $socket, $string)
{
  gere_response(&$player, &$socket, $string);
  
  if ($player["time_fork"] != -1 && 
      $player["timer"] - $player["time_fork"] > 600)
    {
      array_unshift($player["action"], CONNECT_NBR);
      $player["time_fork"] = -1;
    }
  if (!$player['action'])
    find_action(&$player, $socket);
  if (!$player["naction"] && $player['action'])
    new_action(&$player, $socket);
}

?>