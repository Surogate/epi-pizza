<?php

function	std_sincant($player, $msg)
{
  if ($msg[2] == $player['pid_follow'])
    $player['timer_wait'] =  $player['timer'];
}

?>