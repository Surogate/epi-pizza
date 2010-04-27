<?php

function		get_food(&$player)
{
  $inv = $player['inv'];
  $inv = str_replace('{', '', $inv);
  $inv = str_replace('}', '', $inv);
  $inv = explode(',', $inv);

  $food = explode(' ', $inv[0]);
  $player['food'] = intval($food[1]);
}

?>