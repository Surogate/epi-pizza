<?php

function	std_suicide($player, $msg)
{
  if ($player['mode'] == MANAGING)
    {
      if ($player['tmode'][$msg[2]])
	unset($player['tmode'][$msg[2]]); 
      if ($player['tmng'][$msg[2]])
	unset($player['tmng'][$msg[2]]);
    }
  if ($player['tmng'][$msg[2]])
    {
      $player['nally'] -= 1;
      unset($player['tmsg'][$msg[2]]);
    }
}

?>