<?php

function	is_level_rsr($player, $rsr)
{
  if ($player['tlevel'][$player['level']][$rsr] >= $player[$rsr])
    return (true);
  return (false);
}

function	std_ok($player, $socket, $string)
{
  $taction = array_shift($player["tresolve"]);

  if ($taction[0] == "broadcast")
    echo "\n";
  log_ia(&$player, NACTION, MACTION_OK . $taction[0] . " " . $taction[1]);
  if ($taction[0] == PREND)
    {
      $tressource = explode("\n", $taction[1]);
      
      $player[$tressource[0]] += 1;
      if ($tressource[0] != 'nourriture'
	  && is_level_rsr(&$player, $tressource[0]))
	{
	  send_inventaire(&$player);
	}
    }
}

?>