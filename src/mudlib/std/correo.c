/**
 * SIMAURIA '/std/correo.c'
 */

#include <rooms.h>
inherit ROOM;

create() {
  ::create();
  SetIntShort("oficina de correo");
  SetIntLong("Est�s en una oficina de correo de Simauria.\n");
}
