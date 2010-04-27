<?php

function	std_follows($player, $msg)
{
  if ($msg[2] == $player['pid_follow'])
    {
      $case = $msg[1][0];

      if ($case != '0')
	follow_sig(&$player, $case);
      else
	{
	  echo "\n[NOTICE] Je suis arrive\n";
	  drop_rsr(&$player);
	  $msg = create_msg(&$player, ARRIVE . " " . $player['pid_follow']);
          array_push($player['taction'], $msg);
	  echo "[NEW_MODE = ".$player['pid']."] je passe en mode WAITING\n";
	  $player['mode'] = WAITING;
	  log_ia(&$player, NMODE, MMODE_CHANGE . WAITING);
	}
    }
}

?>