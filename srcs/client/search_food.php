<?php

function	search_food(&$player)
{
  $view = str_replace("{", "", $player['view']);
  $view = str_replace("}", "", $view);
  $view = explode(',', $view);
  $inv = str_replace("{", "", $player['inv']);
  $inv = str_replace("}", "", $inv);
  $inv = explode(',', $inv);
  
  $i = 0;
  while ((preg_match("/nourriture/i", $view[$i]) != 1) && ($view[$i] != NULL))
    $i++;
  if (preg_match("/nourriture/i", $view[$i]) == 1)
    {
      $player['reach'] = $i;
      $player['objet'] = "nourriture\n";
    }
  else
    {
      $player['reach'] = 2 * $player['level'];
      $player['objet'] = NULL;
    }
  $i = 0;
  while ((preg_match("/nourriture/i", $inv[$i]) != 1) && ($inv[$i] != NULL))
    $i++;
  $nbr = array();
  $nbr = explode(" ", $inv[$i]);
  $player['food'] = intval($nbr[1]);
}
?>
