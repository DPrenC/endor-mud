
#include <rooms.h>

#include <nightday.h>
#include <properties.h>
#include "path.h"

inherit ROOM;

create(){
  ::create();
  SetIndoors(0);
  SetLocate("bosqueDehim");
  SetIntSmell("Huele a pino.\n");
  SetIntNoise("Escuchas el suave crujir de las ramas.\n");
  SetIntShort("el bosque de la Batalla Perdida");
  SetIntLong("Te internas entre algunos árboles viejos y tupidos de hojas. "
  		"Sus ramas crujen tanto que te hacen rechinar los dientes. "
  		"Algunos no te permiten el paso.\n");
  AddDetail(({"arbol","árboles"}),"No ves muchos pero los que hay son "
  		"fuertes y duraderos, aunque viejos.\n");

  AddExit("norte",ALULAGO("bosque/bosque7"));
}
