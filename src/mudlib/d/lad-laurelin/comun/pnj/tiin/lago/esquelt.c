/* DESCRIPCION    :
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
SetStandard("un esqueleto","no-muerto",20+car,GENDER_MALE);
SetShort("Un esqueleto vagabundea por la zona y te mira");
SetLong("Es todo huesos, no lleva armas.\n");
SetIds(({"esqueleto","muerto"}));   //identificativos
SetAds(({"el","un","tenebroso"}));   //adjetivos feo, alto...
SetAlign(-500);   //alineamiento mas de cero bueno  SetSize(P_SIZE_MEDIUM);  // tamanyo, normal,large, small
SetHands(({({"mano izquierda",0,4}),({"mano derecha",0,8})}));  //manos o garras o ...
SetDex(20+car);
SetInt(10+car);
SetCon(20+car);
SetStr(25+car);
SetAggressive(2);  // agresivo 1=si, 0=no
//SetHP(60+car*8);  //puntos de vida.
//SetMaxHP(60+car*8);

InitChats(2,({  "El esqueleto dice: Jejejeeeeee ...\n",
"El esqueleto dice: moriraaaaaaaaassssss jajajajajaaaaa\n"}));
}