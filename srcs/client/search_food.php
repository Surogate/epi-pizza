<?php

function	search_food(&$player)
{
	/*
  echo "**************************************************************************\n";
  echo "Search food : |" . $player['view'] . "|\n";
  echo "**************************************************************************\n";	
  */
  $view = str_replace("{", "", $player['view']);
  $view = str_replace("}", "", $view);
  $view = explode(',', $view);
  /*
  echo "**************************************************************************\n";
  echo "wich view of food : |" . $view[0] . "\n" . $view[1] . "\n" . $view[2] . "\n" . $view[3] . "|\n";
  echo "**************************************************************************\n";
  */
  echo "**************************************************************************\n";
  echo "Inventaire : |" . $player['inv'] . "|\n";
  echo "**************************************************************************\n";
  
  $inv = str_replace("{", "", $player['inv']);
  $inv = str_replace("}", "", $inv);
  $inv = explode(',', $inv);
  
  $i = 0;
  while ((preg_match("/nourriture/i", $view[$i]) != 1) && ($view[$i] != NULL))
    $i++;
  if (preg_match("/nourriture/i", $view[$i]) == 1)
    {
      echo "VALEUR DE I -> " . $i . "\n";
      $player['reach'] = $i;
      $player['objet'] = "nourriture\n";
    }
    /*
  else if ($i > 0)
    {
      echo "VALEUR DE I -> " . $i . "\n";
      $player['reach'] = $i - 1;
      $player['objet'] = NULL;
    }
    * */
  else
    {
      $player['reach'] = 2 * $player['level'];
      $player['objet'] = NULL;
    }
    /*
  echo "--------------------------------------------------------------------------\n";
  echo "Food is on case: " . $player['reach'] . "\n";
  echo "--------------------------------------------------------------------------\n";
  * */
  $i = 0;
  while ((preg_match("/nourriture/i", $inv[$i]) != 1) && ($inv[$i] != NULL))
    $i++;
  $nbr = array();
  $nbr = explode(" ", $inv[$i]);
  $player['food'] = intval($nbr[1]);
  /*
  echo "--------------------------------------------------------------------------\n";
  echo "Food last: " . $player['food'] . "\n";
  echo "--------------------------------------------------------------------------\n";
 */
}
?>
