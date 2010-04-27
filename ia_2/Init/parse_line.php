<?php
function	parse_line($argc, $argv)
{
  $option = array();
  
  if ($argc == PARAM_NB)
    {
      $option = getopt(PARAM_PATTERN);
      if ($option != false)
	  return ($option);
    }
  print(USAGE);
  exit ;
}
?>