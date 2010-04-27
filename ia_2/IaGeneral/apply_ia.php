<?php

function	apply_ia($player, $socket, $string)
{  
  if (!strncmp($string, MESSAGE, 7) && $player[$player['mode']]['message'])
    $player[$player['mode']]['message'](&$player, &$socket, &$string);
  else if ($player[$player['mode']]['response'])
    $player[$player['mode']]['response'](&$player, &$socket, &$string);
  
  if ($player[$player['mode']]['timer'])
    $player[$player['mode']]['timer'](&$player, &$socket, &$string);
  
  if (!$player['taction'] && $player[$player['mode']]['action'])
    $player[$player['mode']]['action'](&$player, &$socket, &$string);

  if ($player['nourriture'] < 3)
    {
      exec_suicide(&$player);
      return ;
    }

  if (!$player["tresolve"] && $player['taction'])
    new_action(&$player, $socket);

  if (!$player["tresolve"])
    {
      array_push($player['taction'], INVENTAIRE);
      new_action(&$player, $socket);
    }
}

?>