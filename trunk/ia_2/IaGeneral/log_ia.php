<?php

function	ia_die($msg)
{
  echo $msg;
  exit ;
}

function	log_ia($player, $notice, $msg)
{
  if ($player['param']['v'] == 'on')
    echo "$notice <id = " . $player['id'] . "> $msg\n";
}

?>