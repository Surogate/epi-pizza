<?php

function	std_response($player, $socket, $string)
{
  $tstr = explode(" ", $string);

  if ($tstr[0] == OK)
    std_ok(&$player, $socket, $string);
  else if ($tstr[0] == KO)
    std_ko(&$player, $socket, $string);
  else if ($tstr[0] == DEPLACEMENT)
    std_deplacement(&$player, $socket, $string);
  else if ($tstr[0] == MORT)
    std_mort(&$player, $socket, $string);
  else if (ereg(PATTERN_VOIR, $string))
    std_voir(&$player, $socket, $string);
  else if (ereg(PATTERN_INVENTAIRE, $string))
    std_inventaire(&$player, $socket, $string);
  else if (is_numeric($string) == true)
    std_fork(&$player, &$socket, $string);
  else if ($tstr[0] == IS_CASTING)
    std_incant(&$player, &$socket, $string);
  else if ($tstr[0] == ACTUAL_LEVEL)
    std_actuallevel(&$player, &$socket, (int)$tstr[3]);
  else
    echo "message unknown\n";
}

?>