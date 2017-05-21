/*
DESCRIPCION  : Cordillera de Kova
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/montain_4.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Rehecha
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("la cordillera de Kova");
  SetIntLong(
     "Avanzas por una zona de rocas abruptas y altos acantiladoas en la que un paso "
     "en falso puede acabar para siempre con tu vida. Hacia el sur observas una gran "
     "extension boscosa en la que ni los arboles mas altos llegan hasta esta altura. "
     "Un frio gelido recorre tu espalda y tus miembros comienzan a entumecerse, pero "
     "intentas apartar ese pensamiento de tu mente y seguir avanzando con pasos lo "
     "mas firmes que te es posible.\n");

  AddDetail(({"bosque","arboles"}),"Ves como el bosque se extiende hacia el sur.\n");

  SetIntNoise("Reina el silencio.\n");
  SetIntSmell("El aire es algo frio en estas alturas.\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(0);

  AddExit("oeste",Z_BOSQUE("montain_3"));
  AddExit("este",Z_BOSQUE("montain_5"));
  AddExit("noroeste",Z_BOSQUE("montain_2"));

  AddItem(PNJ("animal/urraca"),REFRESH_DESTRUCT);
}

