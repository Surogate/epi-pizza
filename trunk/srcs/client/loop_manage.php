
<?php

function loop_manage($cmd_serv, &$player)
{
	if ($cmd_serv[0] == '{')
		{
			clean(&$cmd_serv);
			what_see($cmd_serv, &$player);
		}
}
?>
