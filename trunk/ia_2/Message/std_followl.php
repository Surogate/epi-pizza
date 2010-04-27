<?php

function	follow_sig($player, $case)
{
  log_ia(&$player, NNOTICE, MNOTICE_FOLLOW . $case);
  if ($case == 1 || $case == 2 || $case == 8)
    array_push($player['taction'], AVANCE);
  else if ($case == 3 || $case == 4 || $case == 5)
    array_push($player['taction'], GAUCHE);
  else if ($case == 6 || $case == 7)
    array_push($player['taction'], DROITE);
  
}

function	std_followl($player, $msg)
{
  if ($msg[2] == $player['pid_follow'])
    {
      $case = (int)$msg[1][0];
      if ($case != 0)
	follow_sig(&$player, $case);
      else
	{
	  drop_rsr(&$player);
	  array_push($player['taction'], AVANCE);
	  $msg = create_msg(&$player, ARRIVE . " " . $player['pid_follow']);
	  array_push($player['taction'], $msg);
	  if ($player['level'] == 0)
	    $player['mode'] = FARMING;
	  else
	    $player['mode'] = FEEDING_LEVELING;
	  log_ia(&$player, NMODE, MMODE_CHANGE . $player['mode']);
	}
    }
}

?>