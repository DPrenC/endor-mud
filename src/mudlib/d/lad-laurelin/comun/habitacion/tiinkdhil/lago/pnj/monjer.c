/*
DESCRIPCION    : Monje fantasma
FICHERO        : /d/lad-laurelin/pnj/lago/monjef.c
CREACION       : 24-11-98 [Alura]
U.MODIFICACION :
*/

#include <rooms.h> // solo para que pueda perseguir
#include <properties.h>

#include "path.h"
inherit "std/undead";

int car;

create() {
  ::create();
  car=random(2)+6;
  SetName("Monje fantasma");
  SetShort("un monje.\n");
  SetLong("Esta arrodillado en uno de los bancos rezando algo. Parece malherido.\n");
  SetRace("no-muerto");
  SetIds(({"fantasma","muerto","monje"}));   //identificativos
  SetAds(({"el","un","demacrado"}));   //adjetivos feo, alto...
  SetLevel(random(2)+6);
  SetAlign(10);
  SetSize(P_SIZE_MEDIUM);  // tamanyo, normal,large, small
  SetAC(1);   //armadura de piel
  SetGender(GENDER_MALE);
  SetHands(({({"mano izquierda",0,1}),({"mano derecha",0,1})}));
  SetAggressive(0);  // agresivo 1=si, 0=no
  SetHP(100);
  SetMaxHP(100);
}
