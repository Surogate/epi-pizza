<?php

function	std_sincruste($player, $msg)
{
  $case = (int)$msg[1][0];
  if ($case != 0)
    follow_sig(&$player, $case);
  else
    {
      log_ia(&$player, NNOTICE, MNOTICE_SINCRUSTE);
      array_push($player['taction'], EXPULSE);
      array_push($player['taction'], PREND . " linemate\n");
      array_push($player['taction'], PREND . " deraumere\n");
      array_push($player['taction'], PREND . " sibur\n");
      array_push($player['taction'], PREND . " mendiane\n");
      array_push($player['taction'], PREND . " phiras\n");
      array_push($player['taction'], PREND . " thystame\n");
    }
}

?>