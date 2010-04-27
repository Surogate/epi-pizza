<?php

require_once 'analyse.php';
require_once 'elevation.php';

function		drop_stones(&$player)
{
  global		$lvl;

  $rocks = fill_rocks();
  $i = 0;
  while ($i < 6)
    {
      $j = 0;
      while ($j < $lvl[$player['level'] + 1][$rocks[$i]])
		{
			fifo_in(&$player, "pose " . $rocks[$i] . "\n");
			$j++;
		}
      $i++;
    }
}

?>
