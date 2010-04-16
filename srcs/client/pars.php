B1;2202;0c<?php
function	pars_init_tab()
{
  $pars[0] = "-n";
  $pars[1] = "-p";
  $pars[2] = "-h";
  $opt[0] = NULL;
  $opt[1] = NULL;
  $opt[2] = "127.0.0.1";
  $all[0] = $pars;
  $all[1] = $opt;
  return ($all);
}

function	pars_display_error($err)
{
  $fp = fopen("php://stderr", 'w');
  fprintf($fp, "usage: ./zappy [options]\n");
  fprintf($fp, "zappy: invalid option/value for -%s\n", $err);
  fprintf($fp, "\033[7m\033[1mZAPPY HELPER 0.1\033[m :");
  fprintf($fp, " Zappy Client 0.1 Available Args\033[m\n"); 
  fprintf($fp, "  \033[1m\033[32m-p\033[m\tPort Number\n");
  fprintf($fp, "  \033[1m\033[32m-n\033[m\tTeam Name\n");
  fprintf($fp, "  \033[1m\033[32m-h\033[m\tClient Name (default : localhost)\n");
  fclose($fp);
  exit(0);
}

function	pars_display_values($opt)
{
  echo "\n\033[1;31m/***************Client Infos***************/\033[m\n\n";
  echo "\033[1;32mServer Port\033[m -> " . $opt[1] . "\n";
  echo "\033[1;32mTeam Name\033[m -> " . $opt[0] . "\n";
  echo "\033[1;32mClient Name\033[m -> " . $opt[2] . "\n\n";
}

function	pars_options($all, $argc, $argv)
{
  $i = 0;
  $j = 1;
  while ($j < $argc)
    {
      while ($i < 3)
	{
	  if ($all[0][$i] == $argv[$j] && $argv[$j + 1][0] != '-')
	    {
	      if (($j + 1) < $argc)
		{
		  $all[1][$i] = $argv[$j + 1];
		  $j++;
		}
	      else
		pars_display_error($argv[$j]);
	    }
	  $i++;
	}
      $i = 0;
      $j++;
    }
  if ($all[1][2] == "localhost")
    $all[1][2] = "127.0.0.1";
  return ($all);
}

function	pars_check_values($opt)
{
  if ($opt[1] == 0)
    {
      echo "\n\033[1;31m!!! Warning \033[m: Port value is out of range";
      echo ", redefinig value to \033[1;31m4242\033[m\n";
      $opt[1] = 4242;
    }
  else if ($opt[1] < 3000 || $opt[1] > 65000)
    {
      echo "\n\033[1;31mPort is out of range [3000 - 65000]\033[m\n\n";
      pars_display_error("-p");
    }
  return ($opt);
}

function	pars_main($argc, $argv)
{
  $all = pars_init_tab();
  $opt = pars_options($all, $argc, $argv);
  $i = 0;
  while ($i < 3)
    {
      if ($opt[1][$i] == NULL)
	pars_display_error($opt[0][$i]);
      $i++;
    }
  $par = pars_check_values($opt[1]);
  pars_display_values($par);
  return ($par);
}

pars_main($argc, $argv);
?>