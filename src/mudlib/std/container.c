/**
 * SIMAURIA '/std/container.c'
 */

#include <classes.h>

inherit "/std/container/restrictions";
inherit "/std/container/description";
inherit "/std/thing/moving";
inherit "/std/base";

create () {
  "*"::create();
  AddClassId(C_CONTAINER);
  SetMaxIntWeight(0);
  SetPreContent("Contiene:\n");
  seteuid(getuid());
}

init() {
  "*"::init();
}
