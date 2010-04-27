<?php

/* general */
define("BUFF_SIZE", 2048);
define("SEP", " ");
define("TIME_INCANT", 300);
define("MAX_FOOD", 50);
define("TIME_ONE_FOOD", 126);
define("RANG_FORK", 15);
define("PATTERN_REPLACE", "('..')");
define("MIN_MANAGE_FOOD", 8);

/* nb_by_mode */
define("SEUIL_LEVELER", 10);
define("SEUIL_FARMER", 12);
define("SEUIL_SPAMMEUR", 16);
define("SEUIL_SINCRUSTE", 22);

/* notices */
define("NERROR", "[ERROR] ");
define("NCONNECT", "[CONNECT]");
define("NACTION", "[ACTION]");
define("NSUICIDE", "[SUICIDE]");
define("NMANAGE", "[MANAGE]");
define("NTIMER", "[TIMER]");
define("NNOTICE", "[NOTICE]");
define("NMODE", "[MODE]");
define("NLEVEL", "[LEVEL]");

/* log_msg */
define('MCONNECT_SUCCESS', "A player has join the game.");
define('MCONNECT_SUCCESS', "A player has left the game.");
define('MACTION_SUICIDE', "A player is suiciding.");
define('MMANAGE_PONDEUSE', "The pondeuse was born.");
define('MMANAGE_MODE', "I manage the modes.");
define('MACTION_NEW', "I send ");
define('MMANAGE_ORDER', "Manager say ");
define('MTIMER_FOLLOW', "Timer follow done.");
define('MTIMER_FORK1', "Timer fork farmer done.");
define('MTIMER_FORK2', "Timer egg done.");
define('MTIMER_INVENTORY', "Timer inventory done.");
define('MTIMER_MANAGE', "Timer manage done.");
define('MTIMER_WAIT', "Timer wait done.");
define('MNOTICE_APPEAL', "I appeal.");
define('MMODE_CHANGE', "I go in the mode ");
define('MNOTICE_FOLLOW', "I heard a appeal in case ");
define('MNOTICE_FAKE', "I recieved a fake message.");
define('MNOTICE_ENNEMY', "I recieved a ennemy message.");
define('MNOTICE_SINCRUSTE', "I expulse ennemy.");
define('MLEVEL_NEW', "I am level ");
define('MACTION_FAILED', "I failed ");
define('MACTION_OK', "I finished ");
define('MLEVEL_INCANT', 'I am incanting.');

/* error_msg */
define('SCREATE_ERR', NERROR . "Can't create the socket.\n");
define('SCONNECT_ERR', NERROR . "Connection refused by the server.\n");
define('SREAD_ERR', NERROR . "Can't read to the socket.\n");
define('SWRITE_ERR', NERROR . "Can't write to the socket.\n");
define('SCLOSE_ERR', NERROR . "Can't close the socket.\n");

/* command line */
define("PARAM_PATTERN", 'h:p:t:n:');
define("PARAM_NB", 9);
define("USAGE", "usage : ./ia -h host -p port -t team -n nb_player 
[--fork off] [--mode pve] [--v on]\n");

/* connexion */
define("CONNECT_SUCCESS", "BIENVENUE\n");
define("CONNECT_FAILURE", "Connexion has been refused by the server\n");
define("CLIENT_ACCEPT", "ko");
define("CLIENT_REFUSE", "Client has een refused y the server\n");

/* mode */
define('FEEDING', 1);
define('FEEDING_LEVELING', 2);
define('LEVELING', 3);
define('MANAGING', 4);
define('CASTING', 5);
define('CALLING', 6);
define('WAITING', 7);
define('SPAMMING', 8);
define('SINCRUSTING', 9);
define('FARMING', 10);
define('PONDING', 11);

/* action */
define("FORK", "fork\n");
define("AVANCE", "avance\n");
define("DROITE", "droite\n");
define("GAUCHE", "gauche\n");
define("VOIR", "voir\n");
define("INVENTAIRE", "inventaire\n");
define("INCANTATION", "incantation\n");
define("EXPULSE", "expulse\n");
define("PREND", "prend");
define("POSE", "pose");
define("BROADCAST", "broadcast");
define("CONNECT_NBR", "connect_nbr\n");

/*  callmode */

define("CONNECT_NBR", "connect_nbr\n");

/* broadcast */
define("MAGIC_NUMBER", "<-private->");
define("NEW_PLAYER", "hi");
define("TOTAL_PLAYER", "nally");
define("INVENTORY", "inventory");
define('FOLLOWL', "followl");
define('FOLLOWS', "follows");
define('DROP', "drop");
define("MANAGE", "manage");
define("LEVELUP", "levelup");
define("COME", "come");
define("START_INCANT", "start_incant");
define("ARRIVE", "arrived");
define("MANAGE_MODE", "manage_mode");
define("ENNEMY", "ennemy");
define("SUICIDE", "suicide");

/* response */
define("OK", "ok");
define("KO", "ko");
define("MESSAGE", "message");
define("DEPLACEMENT", "deplacement");
define("MORT", "mort");
define("PATTERN_VOIR", "^\{([[:alpha:] ,]+)\}$");
define("PATTERN_INVENTAIRE", "^\{([[:alnum:] ,]+)\}$");
define("IS_CASTING", "elevation");
define("ACTUAL_LEVEL", "niveau");


/* delay */
define("DELAY_INCANT", 300);
define('DELAY_HI', 126);
define('DELAY_INVENTAIRE', 126);
define('DELAY_FORK', 300);
define("DELAY_STD_INVENTORY", 42);
define('DELAY_MANAGE', 125);
define('DELAY_MANAGE_INV', 125);

/* boussole */
define("NORD", 1);
define("SUD", 3);
define("EST", 2);
define("OUEST", 4);

?>