<?php

function	create_msg($player, $msg)
{
  $msg = MAGIC_NUMBER . SEP .
    $player["pid"] . SEP . PATTERN_REPLACE . SEP . $player["level"] . SEP . $msg;
  return ('broadcast ' . $msg . "\n");
}

?>