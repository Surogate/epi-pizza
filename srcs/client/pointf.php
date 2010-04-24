<?php

function go_point(&$player)
{
	echo "We did it !!!!!!!!\n";
	echo "Nombre de commandes: " . $player['nb_cmd'] . "\n";
	echo $player['last_receive'];
	out_did(&$player);
}

function toto($s)
{
	echo $s . "\n";
}

function test($pfunc)
{
	$i = 0;
	while ($i < 6)
		{
			$pfunc( "pouet\n" );
			$i++;
		}
}



?>
