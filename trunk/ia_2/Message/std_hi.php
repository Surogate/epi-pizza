<?php

function	std_hi($player, $msg)
{
  if ($player["timer"] > DELAY_HI)
    {
      if ($player["min_pid"] == $player["pid"])
        {
          $player["nally"] = count($player['tmsg']) + 1;
	  echo "[POP = ".$player['pid']."] Il y a " . ($player["nally"] + 1) ." joueurs\n";
          $msg = create_msg(&$player, TOTAL_PLAYER . " " . $player["nally"]);
          array_unshift($player['taction'], $msg);
        }
    }
}

?>