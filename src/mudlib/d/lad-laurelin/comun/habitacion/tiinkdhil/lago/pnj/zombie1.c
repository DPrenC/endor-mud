/*
DESCRIPCION    :
FICHERO        :
CREACION       :
U.MODIFICACION :
*/

#include <rooms.h> // solo para que pueda perseguir

#include "path.h"
#include <properties.h>

inherit NPC;



create() {
  ::create();
  SetName("un muerto viviente");
  SetShort("Un asqueroso zombie que se cae a trozos se dirige hacia ti");
  SetLong("El muerto despide un olor a putrefaccion, esta algo descompuesto.\n");
  SetRace("humano");
  SetIds(({"zombie","muerto"}));   //identificativos
  SetAds(({"el","un","horripilante"}));   //adjetivos feo, alto...
  SetLevel(1);   //nivel
  SetAlign(-1000);   //alineamiento mas de cero bueno
  SetSize(P_SIZE_MEDIUM);  // tamanyo, normal,large, small
  SetAC(1);   //armadura de piel
  SetGender(GENDER_MALE);// male , female, ?neutral? ...
  SetHands(({({"mano izquierda",0,1}),({"mano derecha",0,2})}));  //manos o garras o ...
  SetDex(1);
  SetInt(0);
  SetCon(1);
  SetStr(2);
  SetAggressive(1);  // agresivo 1=si, 0=no
  SetHP(30);  //puntos de vida.
  SetMaxHp(30);

  InitChats(2,({
  "Uuuuouuhhhhhh....uuu\n",
  "comiida...cooomidaaaaa\n"}));

  InitAChats(1,({
  "grrr... grrr...!!\n"}));

}