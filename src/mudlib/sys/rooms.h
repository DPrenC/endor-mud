/* SIMAURIA '/sys/rooms.h'
   =======================
   [g] Guybrush@simauria
   [w] Woo@simauria

   23-11-98 [g] Se carga todo lo referente a puertas antiguas.
   05-04-99 [w] Elimina magic.h.
   06-05-99 [g] Cambio en las salidas.
*/

#ifndef _ROOM_
#define _ROOM_

#include <search.h>

/* entries in (special_)item array */
#define RITEM_FILE     0  /* items only */
#define RITEM_REFRESH  1  /* refreshtype */
#define RITEM_OBJECT   2  /* filename of (first) created object */

/* refreshflags for extra items */
#define REFRESH_NONE	 0  /* Don't refresh */

#define REFRESH_DESTRUCT   1  /* Refresh by recreationwhen destructed */
#define REFRESH_REMOVE	   2  /* Refresh by recreation when removed */
#define REFRESH_MOVE_HOME  4  /* Refresh by moving home */
#define REFRESH_HOME       (REFRESH_DESTRUCT|REFRESH_MOVE_HOME)
#define REFRESH_ALWAYS	   (REFRESH_DESTRUCT|REFRESH_REMOVE)
#define REFRESH_RESET	   8  /* Refresh by calling reset(1) */
#define REFRESH_PROPS	  16  /* Refresh by resetting props */
#define REFRESH_FUNC      32  /* Refresh by calling a function */

/* What the fields in the exits mapping mean */

#define EXIT_DEST   0	/* Either destination room, or destination function */
#define EXIT_DOOR    1	/* Funktion object: also serves as flag */
#define EXIT_HIDDEN 2	/* Flag if the exit is hidden */
#define EXIT_SIZE  3	/* Flag if the exit is to be checked */

#define EXIT_COUNT  4   /* Number of fields in the mapping */

#endif
