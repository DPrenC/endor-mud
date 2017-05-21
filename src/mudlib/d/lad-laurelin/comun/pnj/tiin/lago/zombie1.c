/*  DESCRIPCION    :
FICHERO        :
CREACION       :
U.MODIFICACION :
*/
#include <rooms.h> // solo para que pueda perseguir
#include "path.h"
#include <properties.h>



inherit "std/undead";

create() {
::create();
 seteuid(getuid());
SetStandard("un muerto viviente","no-muerto",26,GENDER_MALE);
SetShort("Un asqueroso zombie");
SetLong("El muerto despide un olor a putrefaccion, esta algo descompuesto.\n");
SetIds(({"zombie","muerto"}));   //identificativos
SetAds(({"el","un","horripilante"}));   //adjetivos feo, alto...
SetAlign(-1000);   //alineamiento mas de cero bueno
SetSize(P_SIZE_MEDIUM);  // tamanyo, normal,large, small
SetHands(({({"mano izquierda",0,9}),({"mano derecha",0,8})}));  //manos o garras o ...
SetInt(5);
SetStr(36);
SetDex(16);
SetAggressive(1);  // agresivo 1=si, 0=no

InitChats(2,({   "El zombie dice: Uuuuouuhhhhhh....uuu\n",
"El zombie gime: comiida...cooomidaaaaa\n"}));
InitAChats(1,({   "El zombie se cabrea: grrr... grrr...!!\n"}));
}