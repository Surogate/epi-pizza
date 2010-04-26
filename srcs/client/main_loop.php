<?php

function main_loop(&$player)
	{
		while (1)
		{
		  if ($player['flag'] == 3)
			routine(&$player);
			$read   = array($player['socket']);
			if ($player['send'][0] != NULL)
				$write  = array($player['socket']);
			else
				$write  = array();
			$except = NULL;
			$num_changed_sockets = socket_select(&$read, &$write, &$except, 0);
			if ($num_changed_sockets === false) 
				aff_error("Select error : " . socket_strerror(socket_last_error()) . "\n", 0);
			else if ($num_changed_sockets > 0) 
				{
					foreach ($read as $value)
						to_read($value, &$player);
					foreach ($write as $val)
						to_write($val, &$player);
				}
		}

	}

?>
