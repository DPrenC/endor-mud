/*  DESCRIPCION    :
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
car=random(5);
::create();
SetStandard("un esqueleto","no-muerto",23+car,GENDER_MALE);
SetShort("Un esqueleto");
SetLong(   "Lleva trozos de alguna estranya vestimenta por el cuerpo.\n");
SetIds(({"esqueleto","muerto"}));   //identificativos
SetAds(({"el","un","tenebroso"}));   //adjetivos feo, alto...
SetAlign(-500);   //alineamiento mas de cero bueno
SetSize(P_SIZE_MEDIUM);  // tamanyo, normal,large, small
SetHands(({({"mano izquierda",0,4}),({"mano derecha",0,8})}));  //manos o garras o ...
SetDex(23+car);
SetInt(10+car);
SetCon(23+car);
SetStr(35+car);
SetAggressive(1);  // agresivo 1=si, 0=no

InitChats(2,({   "Un esqueleto dice: - Jejejeeeeee ...\n",
"El esqueleto dice: - Moriraaaaaaaaassssss jajajajajaaaaa\n"}));      InitAChats(2,({   "El esqueleto te mira y dice: - No saldras de aqui!!!\n","Mueeereee\n"}));
}