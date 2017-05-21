#include <properties.h>

inherit "/std/thing";


void create() {
  ::create();
  AddId("esfera");
  AddId("oscura");
  AddId("oscuridad");
  AddId("esfera_oscura");
  SetWeight(0);
  SetValue(0);
  SetBright(-50);
  SetShort("una esfera de oscuridad");

SetLong("Es una esfera que absorve toda la luz a su alrededor, hecha de la\n\màs intensa oscuridad del abismo.\n");
  Set(P_NOGIVE, 1);
  Set(P_NOGET, 1);
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
  Set(P_NOBUY, 1);
  SetSmell("Huele como si se estuviera consumiendo algún tipo de material.\n");
  if (member(object_name(TO), '#')!=-1) call_out("weg", 1000);
}

void weg() { remove(); }


