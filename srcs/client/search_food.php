<?php
function	search_food(&$player)
{
  $view = str_replace('{', $player['view']);
  $view = str_replace('}', $view);
  $view = explode(', ', $view);

  $i = 0;
  while (preg_match("/nourriture/i", $view[$i]) != 1 && $view[$i] != NULL)
    $i++;
  $player['reach'] = $i;
  $player['objet'] = "nourriture\n";
}
?>
