<?php

function	std_arrive($player, $msg)
{
  if ($msg[6] == $player['pid'])
    $player['ncoming']--;
}

?>