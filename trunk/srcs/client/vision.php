<?php

require_once 'priority.php';
require_once 'str_func.php';

function what_see($around, &$player)
{
  $case = many_case($around);
  clean(&$around);
  $tab = array();
  $tab = explode(',', $around);
  $i = 0;
  $y = 0;
  while ($i < $case)
    {
      $tab_len = strlen($tab[$i]);
      while (($tab[$i][$y] == " ") && ($y < $tab_len))
	{
	  $tab[$i][$y] = "";
	  $y++;
	}
      $y = 0;
      if ((strcasecmp($tab[$i], "") == 0) || (strcasecmp($tab[$i], "\n") == 0))
	echo "c'est videeeeeeeeee \n";
      else
	echo $tab[$i] . "\n \n";
      $i++;
    }
  define_prio(&$player, &$tab);
}

?>
