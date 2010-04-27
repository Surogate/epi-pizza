<?php

function	std_mort($player, $socket, $string)
{
  socket_close($socket);
  log_ia(&$player, NCONNECT, MCONNECT_DONE);
  while (!($socket = init_connect(&$player)));
  init_player(&$player);
  init_level(&$player);
  init_mode(&$player);
  init_ia(&$player, $socket);
}

?>