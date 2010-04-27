<?php

require_once 'analyse.php';
require_once 'elevation.php';

function		drop_stones(&$player)
{
  global		$lvl;

  $rocks = fill_rocks();
  $i = 1;
  while ($lvl[$i][$player['level'] + 1] != NULL)
    {
      $j = 0;
      while ($j < $lvl[$rocks[$i]][$player['level']])
	{
	  fifo_in(&$player, "pose" . $rocks[$i] . "\n");
	  $j++;
	}
      $i++;
    }
}

?>