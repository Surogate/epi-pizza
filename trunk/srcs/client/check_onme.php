<?php

require_once 'elevation.php';

function		check_onme(&$player)
{
  global $lvl;

  $whole = str_replace('{', '', $player['view']);
  $whole = str_replace('}', '', $whole);
  $whole = explode(', ', $whole);
  $mine = $whole[0];
  preg_match_all('/joueur/i', $mine, $table, PREG_SET_ORDER);
  if (count($table) >= $lvl[$player['level']])
    return (1);
  else
    return (0);
}

?>