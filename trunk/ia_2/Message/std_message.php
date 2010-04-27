<?php

function	check_id($player, $msg)
{
  if ($player['tmsg'][$msg[2]] &&
      $player['tmsg'][$msg[2]] >= $msg[3])
    return (false);
  if (!$player['tmsg'][$msg[2]])
    $player["nally"] += 1;
  $player['tmsg'][$msg[2]] = $msg[3];
  if ((int)$msg[2] < (int)$player["min_pid"])
    $player["min_pid"] = (int)$msg[2];
  return (true);
}

function	std_message($player, $socket, $string)
{
  if (strstr($string, MAGIC_NUMBER))
    {
      $msg = explode(" ", $string);
      if (check_id(&$player, $msg))
        {
          if ($player[$player['mode']]['pmsg'][$msg[5]])
            $player[$player['mode']]['pmsg'][$msg[5]](&$player, $msg);
        }
      else
	{
	  log_ia(&$player, NNOTICE, MNOTICE_FAKE);
	}
    }
  else
    {
      log_ia(&$player, NNOTICE, MNOTICE_ENNEMY);
      $player['spam'] = substr($string, 10);
      if ($player[$player['mode']]['pmsg'][ENNEMY])
	$player[$player['mode']]['pmsg'][ENNEMY](&$player, $msg);
    }
}

?>