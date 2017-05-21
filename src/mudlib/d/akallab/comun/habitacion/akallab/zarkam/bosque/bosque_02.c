/*
DESCRIPCION  : Bosque
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_??.c
MODIFICACION : ??-??-?? [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el interior del bosque");
  SetIntLong(
    "Un suelo lleno de ramas caidas, hojas y pequenyas piedras, asi como un techo "
    "natural formado por las frondosas ramas de los arboles, son el unico paisaje que "
    "puedes contemplar. No es nada aconsejable permanecer en lugares como este, nadie "
    "sabe que se puede esconder tras los arbustos, o todavia peor, nadie sabe a que "
    "bestia no le haria falta esconderse...\n");

  AddDetail(({"arbol","arboles","copas"}),
    "Grandes arboles forman este bosque. Te impiden toda la visibilidad que "
    "te pudiera ofrecer el sol, aunque no sabrias decir si todavia es de dia, "
    "o si esta nublado...\n");

  AddDetail(({"arbusto","arbustos"}),
    "Grandes arbustos tupidos son los duenyos de este territorio, indiferentes "
    "frente al resto del mundo, nadie sabe que alimanyas pueden esconder.\n");

  SetIntNoise("Oyes el cantico de los pajaros.\n");
  SetIntSmell("El aire esta limpio y fresco...\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(1);
  SetIntBright(10);

  AddExit("norte",Z_BOSQUE("bosque_10"));
  AddExit("este",Z_BOSQUE("bosque_03"));

  AddItem(PNJ("animal/oso"),REFRESH_DESTRUCT);
}
