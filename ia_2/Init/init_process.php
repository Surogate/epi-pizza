<?php

function	init_process($n)
{
  for ($i = 1; $i < (int)$n; $i++)
    {
      if (!pcntl_fork())
	break ;
    }
}

?>