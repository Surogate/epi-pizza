<?php

function        init_floor()
{
  $i = 0;
  $j = 0;
  $step = 0;
  $limit = 1;
  $floor = array();

  while ($i < 64)
    {
      $floor[$i] = $step;
      $j++;
      if ($j == $limit)
        {
          $limit += 2;
          $step++;
          $j = 0;
        }
      $i++;
    }
  return ($floor);
}


function        init_player($player)
{
  $player['pid'] = getmypid();
  $player["min_pid"] = $player["pid"];
  $player['bmanage'] = false;

  $player["histo_msg"] = array();
  $player["nmsg"] = 1;
  $player["spam"] = "come Bande de chou fleur a poil court";
  $player["tmsg"] = array();

  $player["tally"] = array();
  $player["nally"] = 0;
  $player["bfork"] = true;
  $player["nfork"] = 0;

  $player['nourriture'] = 10;
  $player['linemate'] = 0;
  $player['deraumere'] = 0;
  $player['sibur'] = 0;
  $player['mendiane'] = 0;
  $player['phiras'] = 0;
  $player['thystame'] = 0;;

  $player['taction'] = array();
  $player['tresolve'] = array();
  $player["mode"] = FEEDING;

  $player["tmap"] = array();
  $player["tinv"] = array();

  $player["timer"] = 0;
  $player["ttime_fork"] = array();
  $player["timer_inv"] = -1;
  $player["timer_manage"] = -1;
  $player["timer_wait"] = -1;
  $player["timer_follow"] = -1;
  $player["timer_minv"] = -1;

  $player["tfloor"] = init_floor();
  $player['tmng'] = array();
  $player['ttempo'] = array();
  $player['tmode'] = array();

  $player['pid_follow'] = 0;
  $player['tdrop'] = array();
  $player['ncoming'] = 0;

  $player['bcast'] = false;
}

?>