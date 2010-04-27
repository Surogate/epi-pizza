<?php

function	check_id($player, $msg)
{
  if ($player['tmsg'][$msg[2]] >= $msg[3])
    return (false);
  if (!$player['tmsg'][$msg[2]])
    $player["nally"] += 1;
  $player['tmsg'][$msg[2]] = $msg[3];
  if ((int)$msg[2] < (int)$player["min_pid"])
    $player["min_pid"] = (int)$msg[2];
  return (true);
}

function	gere_message($player, $socket, $string)
{
  /* echo "message + $string\n";*/
  
  if (strstr($string, MAGIC_NUMBER))
    {
      $msg = explode(" ", $string);
      if (check_id(&$player, $msg))
	$player['pmsg'][$msg[4]](&$player, $msg);
      else
	echo "fake";
    }
  else
    echo "pas a nous";
}

?>