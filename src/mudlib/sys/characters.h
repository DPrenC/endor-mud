/**
 * /sys/characters.h
 */

#ifndef _CHARACTERS_
#define _CHARACTERS_

// tipos de validaciones:
#define NICK_PENDING     -2
#define NICK_UNKNOWN     -1
#define NICK_INVALID     0
#define NICK_VALID       1

// baneados
#define NICK_UNBANISHED  0
#define NICK_BANISHED    1

#define EMAIL_UNBANISHED 0
#define EMAIL_BANISHED   1

// momias
#define NICK_UNMUMMIFIED 0
#define NICK_MUMMIFIED   1


// flags para el array de resultados de la tabla valid_names
#define N_ID             0
#define N_NAME           1
#define N_WIZ            2
#define N_DATE           3
#define N_MODE           4
#define N_REASON         5


// tabla de baneados
#define N_BAN_ID             0
#define N_BAN_NAME           1
#define N_BAN_WIZ            2
#define N_BAN_DATE           3
#define N_BAN_REASON         4
#define N_BAN_UNTIL          5

//Tabla de e-mails baneados
#define E_BAN_ID             0
#define E_BAN_EMAIL           1
#define E_BAN_WIZ            2
#define E_BAN_DATE           3
#define E_BAN_REASON         4
#define E_BAN_UNTIL          5


// flags para funciones
#define CH_STATUS         0
#define CH_INFO           1 // muestra toda la información sobre el nick aceptado o rechazado
#define CH_FORCE_CHECK    1 // fuerza la comprobación en QueryValidName, aunque esté desactivado.
#define CH_PROMPT         1
#endif
