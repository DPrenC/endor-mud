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
  car=random(2)+24;
  SetStandard("un monje fantasma","no-muerto",car,GENDER_MALE);
  SetShort("un gran monje no-muerto");
  SetLong("El cadaver de un monje bastante obeso esta en la mesa comiendo algo\n"+
  			"que no ves.\n");
  SetIds(({"fantasma","muerto","monje","gordo"}));
  SetAds(({"el","un","demacrado"}));
  SetAlign(10);
  SetSize(P_SIZE_MEDIUM);
  SetHands(({({"mano derecha",0,5}),({"mano izquierda",0,5})}));
  SetAggressive(0);
  AddItem("/d/lad-laurelin/comun/objeto/proteccion/collar_ajos",REFRESH_REMOVE,SF(wearme));
}


