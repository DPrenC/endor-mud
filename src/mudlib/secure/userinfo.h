#ifndef _SECURE_USERINFO_
#define _SECURE_USERINFO_

/*
 * userinfo: what each field of /secure/PASSWD is
 * [t] Theuzifan
 * 02/12/97 [t] Quitado el #define USER_DOMAIN 3 para cargar la info del dominio
 *  	    del archivo de player
 */

/* id in the database */
#define USER_ID 0

/* login name */
#define USER_NAME 1

/* password (encrypted) */
#define USER_PASSWORD 2

/* wizard level (or programming level) (0 for simple users) */
#define USER_LEVEL 3

/* Player's age of creation */
#define USER_CREATION 4

/* Player's age on last promotion */
#define USER_PROMOTION 5

/* Who promoted the player to learnership? */
#define USER_ELPROMO 6

/* The main character of this player */
#define USER_MAIN_CHARACTER 7

/* last connection */
#define USER_LAST_TIME      8
#define USER_EMAIL          9
#define USER_AUTH_CODE      10
#define USER_AUTHORIZED     11

/* For internal use of the master: time the userinfo was last touched */
#define USER_TOUCH          12


/* índices para el array de información devuelto por find_secundary_characters y find_associated_characters */
#define AR_ID              0
#define AR_NAME    1
#define AR_LEVEL           2
#define AR_CREATION        3
#define AR_LAST_TIME       4
#define AR_CONNECTED       5
/* ordenación de find_secundary_character y find_asociated_characters */
#define ORDER_CREATION      0
#define ORDER_LAST_TIME    1

#endif
