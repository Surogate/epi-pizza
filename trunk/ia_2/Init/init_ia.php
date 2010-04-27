<?php

function	init_ia($player, $socket)
{
  $msg = create_msg(&$player, NEW_PLAYER);

  array_push($player['taction'], $msg);
  new_action(&$player, $socket);
}

?>