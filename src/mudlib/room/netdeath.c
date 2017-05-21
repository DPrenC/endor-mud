/* SIMAURIA '/room/netdeath.c'
   ===========================
   [w] Woo@simauria

   07-04-99 [w] Ahora hereda /std/habitacion y ademas he incluido magia.h
*/

#include <stdrooms.h>
#include <moving.h>
#include <wizlevels.h>
#include <rooms.h>
#include <magia.h>

inherit ROOM;

#define PREV PO

public void create() {
  ::create();
  SetIntShort("Habitacion de las Almas Perdidas");
  SetIntLong("Una habitacion sencilla, disenyada para mantener frescas las estatuas.\n");
  SetTPort(TPORT_NO);
  AddExit("central", CENTER);
}

public void clean() {
  object * inv;

  while (remove_call_out("clean") >= 0) /* skip */;
  inv = all_inventory(TO);
  inv = inv - filter(inv, SF(query_once_interactive));
  filter_objects(inv, "remove");
  filter(inv-({ 0 }), SF(destruct));
}

public varargs int allow_enter(int method, mixed extra) {
  if (find_call_out("clean") < 0)
    call_out("clean", 10);
  return  ((!interactive(PREV) && query_once_interactive(PREV))
           || IS_ARCH(PREV))
          ? ::allow_enter(method, extra)
          : ME_NO_ENTER;
}

public varargs int remove (int method)
{
  clean();
  if (!first_inventory())
    destruct(TO);
  else
    return 1;
}

public varargs int clean_up(int arg) {
  return remove();
}

public void reset() {
  clean();
}
