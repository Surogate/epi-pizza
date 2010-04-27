<?php

function	action_farming($player, $socket, $string)
{
  $tneed = array();
  
  array_push($tneed, 'nourriture');
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
}

?>