<?php

function	loop_action($player, $socket)
{
  $buffer = "";

  while (1)
    {
      if (false == ($vbuffer = @socket_read($socket, BUFF_SIZE)))
	ia_die(SREAD_ERR);
      $buffer .= $vbuffer;
      while ($pos = strpos($buffer, "\n"))
	{
	  $string = substr($buffer, 0, $pos);
	  $buffer = substr($buffer, $pos+1);
	  apply_ia(&$player, &$socket, trim($string));
	}
    }
}

?>