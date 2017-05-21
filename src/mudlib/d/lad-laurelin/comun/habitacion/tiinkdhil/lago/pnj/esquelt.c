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
  car=random(7);
  ::create();
  SetName("un esqueleto");
  SetShort("Un esqueleto vagabundea por la zona y te mira");
  SetLong("Es todo huesos, no lleva armas.\n");
  SetRace("no-muerto");
  SetIds(({"esqueleto","muerto"}));   //identificativos
  SetAds(({"el","un","tenebroso"}));   //adjetivos feo, alto...
  SetLevel(1+car);   //nivel
  SetAlign(-500);   //alineamiento mas de cero bueno
  SetSize(P_SIZE_MEDIUM);  // tamanyo, normal,large, small
  SetAC(1);   //armadura de piel
  SetGender(GENDER_MALE);// male , female, ?neutral? ...
  SetHands(({({"mano izquierda",0,1}),({"mano derecha",0,1})}));  //manos o garras o ...
  SetDex(2+car);
  SetInt(1+car);
  SetCon(2+car);
  SetStr(3+car);
  SetAggressive(1);  // agresivo 1=si, 0=no
  SetHP(50+car*8);  //puntos de vida.
  SetMaxHP(30+car*8);

   InitChats(2,({
  "El esqueleto dice: Jejejeeeeee ...\n",
  "El esqueleto dice: moriraaaaaaaaassssss jajajajajaaaaa\n"}));


}