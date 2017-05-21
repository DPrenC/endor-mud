/*
DESCRIPCION    : pnj base
FICHERO        : DIRECCION/FICHERO
CREACION       : 12-1-98 [koel].
U.MODIFICACION :
*/

//#include <rooms.h> solo para que pueda perseguir

#include "path.h"
#include <properties.h>



inherit "std/undead";

create() {
  ::create();
  seteuid(getuid());
  SetStandard("Sacerdote","no-muerto",16,GENDER_MALE);
  SetShort("sacerdote de Dehim fantasma");
  SetLong(
  "Es el cadaver viviente del Sacerdote superior de la orden.\n"
  "Te mira con aire digno y mueve su baculo con nerviosismo.\n"
  "Todavia cree que esta vivo ...\n");
  SetIds(({"sacerdote","muerto","fantasma"}));
  SetAds(({"demacrado","altivo","el"}));
  SetAlign(0);   //alineamiento mas de cero bueno
  SetSize(P_SIZE_MEDIUM);
  SetHands(({({"mano derecha",0,1}),({"mano izquierda",0,2})}));
  SetDex(13);
  SetInt(15);
  SetCon(15);
  SetStr(22);
  SetAggressive(0);  // agresivo 1=si, 0=no 2=agresivo con npcs

  AddQuestion(({"estatuilla", "estatua"}),
  "Era la ofrenda que le hicimos a nuestro dios ante su imagen.\n"
  "Necesitamos esa figura para recuperar su gracia ...\n"
  );
  AddQuestion(({"radhul","radhul el vampiro"}),
  "Te contesta: Es el malhadado ser que nos ha robado el sagrado medallon.\n"
  "Ha invadido toda la isla y esta acabando con nuestros feligreses\n"
  );
  AddQuestion(({"dehim","el dios dehim"}),
  "Te contesta: Es el dios de la curacion. Los monjes y peregrinos de este lugar hemos\n"
  "estado siempre dedicados a servirle.\n"
  );
  AddQuestion(({"como recuperar la estatuilla"}),
  "Te contesta: Esta escondida en algun lugar del templo ...\n");

  AddItem(("/d/lad-laurelin/comun/objeto/arma/baculo"),REFRESH_REMOVE,SF(wieldme));

  InitChats(10,({
  "El sacerdote dice: Has visto la estatuilla?\n",
  "El sacerdote se lamenta: Hemos perdido la gracia de Dehim, que desastre!\n",
  "El sacerdote clama: Maldito sea cien veces Radhul el vampiro!\n"}));

  InitAChats(10,({
  "El sacerdote grita: Que la colera de Dehim caiga sobre ti!\n"}));
}
