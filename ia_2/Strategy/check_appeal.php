<?php

function	check_appeal($player, $socket)
{
  $nplayer = count(explode("joueur", $player["map"][0])) - 1;

  if ($nplayer < $player["tlevel"][$player["level"]]["joueur"])
    {
      $msg = create_msg(&$player, COME . " " . $player["level"]);
      array_push($player['action'], $msg);
    }
  else if ($nplayer == $player["tlevel"][$player["level"]]["joueur"])
    {
      $msg = create_msg(&$player, START_INCANT . " " . $player["level"]);
      array_push($player['action'], $msg);
      echo "START INCANT\n";
    }
  else if ($nplayer > $player["tlevel"][$player["level"]]["joueur"])
      array_push($player['action'], "expluse\n");
  $player['voir'] = false;
}

?>