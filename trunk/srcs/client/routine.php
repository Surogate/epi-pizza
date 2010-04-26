<?php
function routine(&$player)
{
	$player['view'] = NULL;
	$player['inv'] = NULL;
	fifo_in(&$player, "voir\n");
	fifo_in(&$player, "inventaire\n");
}
?>
