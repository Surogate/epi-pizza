#!/usr/pkg/bin/php
<?php

require_once('Header/library.php');
require_once('Header/require.php');
require_once('Header/define.php');

/* parse_line */
$param = parse_line($argc, $argv);

/* init_process  */
init_process((int)$param['n']);

/* init_player */
$player = init_player($param);

/* init_connexion */
$socket = init_connect($param['h'], (int)$param['p'], $param['t'], &$player);

/* init_level */
init_level(&$player);

/* init_mode */
init_mode(&$player);

/* init_message */
init_message(&$player);

/* init_ia */
init_ia(&$player, $socket);

/* exec_ia */
loop_action($player, $socket);

socket_close($socket);
?>
