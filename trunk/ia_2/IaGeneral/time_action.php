<?php

function        time_action($player, $action_name)
{
  static $stimer = 0;
  static $ptimer = 0;

  switch ($action_name)
    {
    case AVANCE:
      $player["timer"] += 7;
      break ;
    case DROITE:
      $player["timer"] += 7;
      break ;
    case GAUCHE:
      $player["timer"] += 7;
      break ;
    case VOIR:
      $player["voir"] = true;
      $player["timer"] += 7;
      break ;
    case INVENTAIRE:
      $player["timer"] += 1;
      break ;
    case PREND:
      $player["timer"] += 7;
      break ;
    case POSE:
      $player["timer"] += 7;
      break ;
    case EXPULSE:
      $player["timer"] += 7;
      break ;
    case BROADCAST:
      $player["timer"] += 7;
      break ;
    case INCANTATION:
      $player["timer"] += 300;
      break ;
    case FORK:
      $player["timer"] += 42;
      $player["nfork"] += 1;
      array_push($player["ttime_fork"], $player["timer"]);
      break ;
    }
  $stimer = $player["timer"];

  if (((int)$use = ($stimer - $ptimer) / TIME_ONE_FOOD))
    {
      $ptimer = $stimer;
      $player["nourriture"] -= (int)$use;
    }
}

?>