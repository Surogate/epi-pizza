<?php

function        mode_leveling($player, $socket)
{
  $tneed = array();

  if ($player['voir'] == true)
    {
      foreach ($player['tlevel'][$player['level']] as $key => $val)
	{
	  if ($player[$key] < $val)
	    array_push($tneed, $key);
	}
      if (!$tneed)
	{
	  ready_to_level(&$player);
	  array_push($tneed, 'nourriture');
	}
      create_way(&$player, $socket, $tneed);
    }
  else
    array_push($player["action"], VOIR);
}

?>