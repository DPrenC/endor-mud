/*
DESCRIPCION    : Monje fantasma
FICHERO        : /d/lad-laurelin/pnj/lago/monjef.c
CREACION       : 24-11-98 [Alura]
U.MODIFICACION :
*/

#include <rooms.h> // solo para que pueda perseguir
#include "path.h"
#include <properties.h>


inherit "std/undead";

int car;

create() {
  ::create();
  seteuid(getuid());
  car=random(2)+20;
  SetStandard("monje fantasma","no-muerto",random(2)+26,GENDER_MALE);
  SetShort("un monje zombie");
  SetLong("Esta arrodillado en uno de los bancos rezando algo. Parece malherido.\n");
  SetIds(({"fantasma","muerto","monje"}));
  SetAds(({"el","un","demacrado"}));
  SetAlign(10);
  SetSize(P_SIZE_MEDIUM);
  SetHands(({({"mano izquierda",0,2}),({"mano derecha",0,1})}));
  SetAggressive(0);
}
