
<?php

require_once 'did.php'

function loop_manage($cmd_serv, &$player)
{
	which_ans(&$player);
	
	if ($cmd_serv[0] == '{')
		{
			clean(&$cmd_serv);
			what_see($cmd_serv, &$player);
		}
	
}
?>
