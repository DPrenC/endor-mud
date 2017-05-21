/**
 * SIMAURIA '/std/correo.c'
 */

#include <rooms.h>
inherit ROOM;

create() {
  ::create();
  SetIntShort("oficina de correo");
  SetIntLong("Estás en una oficina de correo de Simauria.\n");
}
