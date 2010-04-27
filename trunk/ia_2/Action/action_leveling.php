<?php

function	action_leveling($player, $socket, $string)
{
  $tneed = array();

  if ($player['tmap'])
    {
      foreach ($player['glevel'][$player['level']] as $key => $val)
        {
          if ($player[$key] < $val && $key != 'joueur')
            array_push($tneed, $key);
        }
      create_way(&$player, $socket, $tneed);
    }
  else
    array_push($player["taction"], VOIR);
  
  if ($player['nourriture'] < nb_food_to_level(&$player) * 4)
    {
      log_ia(&$player, NMODE, MMODE_CHANGE . FEEDING_LEVELING);
      $player['mode'] = FEEDING_LEVELING;
    }
}

?>