<?php

function	new_action($player, $socket)
{
  $action = array_shift($player["taction"]);
  $t_action = explode(" ", $action);

  log_ia(&$player, NACTION, MACTION_NEW . $action);
  if ($t_action[0] == POSE)
    $player[$t_action[1]] -= 1;

  if ($t_action[0] == BROADCAST)
    {
      $action = str_replace(PATTERN_REPLACE, 
			    (string)$player["nmsg"], $action);
      $player["nmsg"] += 1;
    }

  time_action(&$player, $t_action[0]);
  
  if (false == @socket_write($socket, $action))
    ia_die(SWRITE_ERR);
  array_push($player["tresolve"], $t_action);
}

?>