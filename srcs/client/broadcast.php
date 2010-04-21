<?php

function broad_send(&$player, $missive)
{
	$to_broad = "broadcast " . $missive;
	fifo_in(&$player, $to_broad);
}

function broad_recv(&$player, $text)
{
	
}
?>
