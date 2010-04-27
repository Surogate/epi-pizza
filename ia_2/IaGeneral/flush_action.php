<?php

function	flush_action($player)
{
  unset($player['taction']);
  $player['taction'] = array();
}

?>