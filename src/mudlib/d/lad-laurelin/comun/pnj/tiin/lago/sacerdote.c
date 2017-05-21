/*
DESCRIPCION    : Sacerdote fantasma QUEST
FICHERO        : /d/lad-laurelin/pnj/lago/sacerdote.c
CREACION       : Agosto del 2001 [Alura]
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
  SetStandard("un sacerdote","no-muerto",30,GENDER_MALE);
  SetShort("sacerdote");
  SetLong("Izrun era el segundo de la orden clerical de este viejo templo cuando.\n"
  "fué asesinado. Se dice que fué él el último monje que sobrevivió al mal.\n");
  SetIds(({"sacerdote","izrun"}));
  SetAlign(100);
  SetSize(P_SIZE_MEDIUM);
  SetHands(({({"mano izquierda",0,6}),({"mano derecha",0,6})}));
  SetAggressive(0);
  Set(P_CANT_FIGHT,"No puedes atacar a este ser incorpóreo.\n");

  InitChats(5,({"El sacerdote te dice: Castígame mortal porque he pecado.\n",
		"El sacerdote dice: Esa mala criatura me traicionó... sisi me engañó...\n",
		"El sacerdote dice: Ella me decia que queria ver su cara. Yo no pensé...\n"}));

    AddQuestion(({"pecado"}),
  "El sacerdote se araña la piel mientras te dice en voz baja: Traicioné a mi dios.\n");

   AddQuestion(({"ella"}),
  "Izrun dice: Ella.. era una mujer de la noche.. pero yo no lo sabia\n"
  "lo juro, parecía tan necesitada... tan enferma... que le enseñé la faz\n"
  "de mi dios.\n");

   AddQuestion(({"faz de Dehim","faz de dios"}),
  "Izrun te dice: Nos ayudarás? si?\n"
  "- La estatuilla... ella me olló rezar después de mover la grande, y luego rezó\n"
  "las palabras para... entregársela a su señor!\n");

  AddQuestion(({"palabras","rezo"}),
  "El sacerdote te dice: Has de rezar a Dehim:\n"
  "Bondadoso Dehim abreme la puerta de tu casa\n");

  AddQuestion(({"grande"}),
  "El sacerdote deja de hacerte caso y grita mientras se golpea: Yo\n"
  "no lo sabia!!");

 AddQuestion(({"estatuilla", "estatua"}),
  "Era la viva imagen de nuestro dios. Es sagrada.\n"
  "Necesitamos esa figura para recuperar su gracia y está escondida en\n"
  "algún lugar del templo.\n");
}
