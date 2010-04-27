<?php

function	create_msg($player, $msg)
{
  $msg = MAGIC_NUMBER . SEP .
    $player["pid"] . SEP . $player["nmsg"] . SEP . $msg;
  $player["nmsg"] += 1;
  return ('broadcast ' . $msg . "\n");
}

?>