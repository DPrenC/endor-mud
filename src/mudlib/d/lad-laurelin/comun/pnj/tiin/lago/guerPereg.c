/*
DESCRIPCION    : Muerto vivo que representa una semielfa peregrina
FICHERO        : guerPereg.c
CREACION       : Junio 2001 (Alura)
*/

#include <rooms.h> // solo para que pueda perseguir
#include <properties.h>
#include "path.h"

inherit "std/undead";

create() {
  ::create();
  seteuid(getuid());
  SetStandard("una fantasma","no-muerto",20,GENDER_FEMALE);
  SetShort("El fantasma de una peregrina");
  SetLong("Tienes ante ti la figura de una semielfa muerta tiempo ha.\n"
"Tiene el cabello trenzado, sus ropas, aunque alegres están "
"confeccionadas para proteger de golpes. Por su aspecto, parece que era una guerrera.\n");
  SetIds(({"semielfa muerta","semielfa","fantasma de peregrina","peregrina"}));
  SetAlign(100);
  SetSize(P_SIZE_MEDIUM);
  SetHands(({({"mano izquierda",0,5}),({"mano derecha",0,7})}));
  SetAggressive(0);

  AddItem("/d/lad-laurelin/comun/objeto/arma/mazaAli",REFRESH_REMOVE,SF(wieldme));
  AddItem("/d/lad-laurelin/comun/objeto/arma/mazaAli",REFRESH_REMOVE,SF(wieldme));
  //AddItem("/d/lad-laurelin/comun/objeto/arma/",REFRESH_REMOVE,SF(wearme));

 }