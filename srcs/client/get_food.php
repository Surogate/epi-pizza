<?php

function		get_food(&$player)
{
  $inv = $player['inv'];
  $inv = str_replace('{', '', $inv);
  $inv = str_replace('}', '', $inv);
  $inv = explode(',', $inv);
  
  $food = explode(' ', $inv[0]);
	if (intval($food[1]) != 0)
		{
			echo "MOYEUSUIKON\n";
			echo "VALEUR DE INTVAL(FOOD) -> " . intval($food[1]);
			$player['food'] = intval($food[1]);
		}
	else
		echo "TU SUXXX TU SUXXX ET TU RESUXXXX\n";
}

?>
