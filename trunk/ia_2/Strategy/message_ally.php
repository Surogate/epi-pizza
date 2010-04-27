<?php

function	message_start_incant($player, $msg)
{
  $case = (int)$msg[1][0];
  if ($player["level"] == (int)$msg[5] &&
      $case != 0)
    {
    $player["mode"] = FEEDING;
    echo "REAPERE A SES OCCUPATIONS\n";
    }
  else
    {
      echo "INCANTATION STARTEDDDDDDDDD\n";
      unset($player['action']);
      $player['action'] = array();
    }
}

function	message_come($player, $msg)
{
  if ($player["level"] == (int)$msg[5] &&
      $player["mode"] == FOLLOW_APPEAL)
    {
      $case = (int)$msg[1][0];
      
      if ($case == 1 || $case == 2 || $case == 8)
	array_push($player['action'], AVANCE);
      else if ($case == 3 || $case == 4 || $case == 5)
	array_push($player['action'], GAUCHE);
      else if ($case == 6 || $case == 7)
	array_push($player['action'], DROITE);
    }
}

function	message_ok_levelup_player($player, $msg)
{
  if ($player["blevel"] == true && 
      $msg[5] == $player['pid'] &&
      $msg[6] == $player['level'])
    {
      $player["tpidlevel"][$msg[2]] = $msg[2];
      if (count($player["tpidlevel"]) >=
	  ($player["tlevel"][$player["level"]]["joueur"] - 1))
	{
	  unset($player['action']);
	  $player['action'] = array();
	  $player["mode"] = APPEAL;
	  $msg = create_msg(&$player,  START_APPEAL . " " .
			    $player["level"]);
	  array_push($player['action'], $msg);
	  echo "SUCCESS\n";
	}
    }
}

function	message_start_appeal($player, $msg)
{
  if ($player["level"] == (int)$msg[5] &&
      food_to_level(&$player) &&
      ($player["mode"] == FEEDING ||
       $player["mode"] == LEVELING ||
       $player["mode"] == FEEDING_LEVELING))
    {
      unset($player['action']);
      $player['action'] = array();
      $player["mode"] = FOLLOW_APPEAL;
      echo "PLAYER FOLLOW\n";
    }
}

function	message_census_player($player, $msg)
{
  echo "RECU ". $msg[5] . " " . $player["level"] . " " . real_food($player["nourriture"], $player["timer"]) . "\n";

  if ($player["level"] == (int)$msg[5])
    $player["time_ok"] = $player["timer"];

  if ($player["level"] == (int)$msg[5] &&
      food_to_level(&$player) &&
      ($player["mode"] == FEEDING ||
       $player["mode"] == LEVELING ||
       $player["mode"] == FEEDING_LEVELING))
    {
      $msg = create_msg(&$player, OK_LEVELUP . " " .
			$msg[2] . " " . $player["level"]);
      array_push($player['action'], $msg);
      $player["time_ok"] = $player["timer"];
      echo "OK\n";
    }
}

function	message_total_player($player, $msg)
{
  $player["nally"] = (int)$msg[5];
}

function	message_new_player($player, $msg)
{
  if ($player["timer"] > DELAY_HI)
    {
      if ($player["min_pid"] == $player["pid"])
	{
	  $player["nally"] = count($player['tmsg']);
	  $msg = create_msg(&$player, TOTAL_PLAYER . " " . $player["nally"]);
	  array_push($player['action'], $msg);
	}
    }
}

?>
