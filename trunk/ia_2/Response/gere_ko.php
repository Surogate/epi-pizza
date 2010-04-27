<?php

function	gere_ko($player, $socket, $string)
{
  unset($player['action']);
  $player['action'] = array();
  array_shift($player["naction"]);
  return ;
}

?>