<?php

function many_case($chaine)
{
	$chaine = str_replace(',', ',', $chaine, $counter);
	return ($counter + 1);
}

function clean(&$str)
{
	echo "CLEAN \n";
	$str = str_replace("{", "", $str);
	$str = str_replace("}", "", $str);
	$str = str_replace("\n", "", $str);
}

function what_see($around, $player)
{
	$case = many_case($around);
	clean(&$around);
	$tab = array();
	$tab = explode(',', $around);
}

?>
