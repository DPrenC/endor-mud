/*
DESCRIPCION    :
FICHERO        :
CREACION       :
U.MODIFICACION :
*/

#include <rooms.h> // solo para que pueda perseguir
#include <properties.h>
#include "path.h"
inherit "std/undead";
int car;


create() {
  car=random(3);
  ::create();
 seteuid(getuid());
  SetStandard("un esqueleto","no-muerto",23+car,GENDER_MALE);
  SetShort("Un guerrero esqueleto");
  SetLong("Debio ser un guerrero antaño. Ahora no tiene mas que huesos.\n");
  SetIds(({"esqueleto","guerrero esqueleto"}));   //identificativos
  SetAlign(-300);   //alineamiento mas de cero bueno
  SetSize(P_SIZE_MEDIUM);  // tamanyo, normal,large, small
  SetHands(({({"mano izquierda",0,3}),({"mano derecha",0,6})}));  //manos o garras o ...
  SetDex(17+car);
  SetInt(7+car);
  SetCon(38+car);
  SetStr(23+car);
  SetAggressive(1);  // agresivo 1=si, 0=no

  AddItem("/d/lad-laurelin/comun/objeto/proteccion/casco",REFRESH_REMOVE,SF(wearme));
  AddItem("/d/lad-laurelin/comun/objeto/proteccion/escudo",REFRESH_REMOVE,SF(wearme));
  AddItem("/d/lad-laurelin/comun/objeto/arma/espada-larga",REFRESH_REMOVE,SF(wieldme));


 }
