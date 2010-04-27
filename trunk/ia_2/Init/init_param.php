<?php

function	init_param($argc, $argv)
{
  $option = array();  

  if ($argc >= 9 && $argc <= 15)
    {
      $option = getopt(PARAM_PATTERN, array("fork:", "mode:", "v:"));
      if ($option != false)
	return ($option);
    }
  print(USAGE);
  exit ;
}

?>