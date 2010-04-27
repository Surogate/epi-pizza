<?php

function many_case($chaine)
{
  $chaine = str_replace(',', ',', $chaine, $counter);
  return ($counter + 1);
}

function clean(&$str)
{
  $str = str_replace("{", "", $str);
  $str = str_replace("}", "", $str);
  $str = str_replace("\n", " ", $str);
}

?>
