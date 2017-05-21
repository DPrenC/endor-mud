/*
DESCRIPCION  : Zona frondosa en el bosque de Zarkam.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_??.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el interior del bosque");
  SetIntLong(
"Un suelo lleno de ramas caidas, hojas y pequenyas piedras, asi como un "
"techo natural formado por las frondosas ramas de los arboles, son el unico "
"paisaje que puedes contemplar. "
"No es nada aconsejable permanecer en lugares como este, nadie sabe que se "
"puede esconder tras los arbustos, o todavia peor, nadie sabe a que bestia "
"no le haria falta esconderse...\n");
  SetIndoors(1);
  SetIntBright(10);
  AddExit("norte",Z_BOSQUE("bosque_38"));
  AddExit("oeste",Z_BOSQUE("bosque_27"));
  AddExit("sur",Z_BOSQUE("bosque_18"));
  AddDetail(({"arbol","arboles","copas"}),
  "Grandes arboles forman este bosque. Te impiden toda la visibilidad que "
  "te pudiera ofrecer el sol, aunque no sabrias decir si todavia es de dia, "
  "o si esta nublado...\n");
  AddDetail(({"arbusto","arbustos"}),
  "Grandes arbustos tupidos son los duenyos de este territorio, indiferentes "
  "frente al resto del mundo, nadie sabe que alimanyas pueden esconder.\n");
  AddDetail(({"ramas","hojas","piedras"}),
  "El suelo esta lleno de ramas, hojas y piedras... Al avanzar las pisas, sin "
  "poder evitarlo, provocando mas ruido del que te gustaria hacer...\n");
  SetIntNoise("Oyes crujir las ramas cuando las pisas.\n");
  SetIntSmell("El aire esta limpio y fresco...\n");
}
