<?php

function aff_error($str, $error)
{
  echo "Error: " . $str . "\n";
  if ($error == 0)
    exit(0);
  else
    return (0);
}

function aff($string, $value)
{
  echo $string . $value . "\n";
}

?>
