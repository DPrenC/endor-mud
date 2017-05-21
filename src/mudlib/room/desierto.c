/* SIMAURIA '/room/desierto.c'
   ======================
   [w] Woo@simauria

   10-12-98 [w] Habitacion donde se mueven temporalmente las caravanas.
*/

#include <moving.h>

inherit ROOM;

public void create()
{
  ::create();
  SetIntShort("En medio del desierto");
  SetIntLong("Arena, arena.. y mas arena.\n");
  SetIndoors(0);
}

