<?php

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
      $i++;
    }
  define_prio(&$player, &$tab);
}

?>
