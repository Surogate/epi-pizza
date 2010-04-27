<?php

function	std_ko($player, $socket, $string)
{
  $tresolve = array_shift($player["tresolve"]);

  log_ia(&$player, NACTION, MACTION_FAILED . $tresolve[0] . " " . $tresolve[1]);

  echo "[!ACTION : " . $player['pid'] ."] " .$player['timer']. " J'ai loupe mon action " . $tresolve[0] ." " . $tresolve[1];
  
  if ($tresolve[0] == INCANTATION)
    $player['mode'] = FEEDING;
}

?>