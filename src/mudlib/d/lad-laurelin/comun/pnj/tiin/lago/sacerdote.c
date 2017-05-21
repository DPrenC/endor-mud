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
  "fu� asesinado. Se dice que fu� �l el �ltimo monje que sobrevivi� al mal.\n");
  SetIds(({"sacerdote","izrun"}));
  SetAlign(100);
  SetSize(P_SIZE_MEDIUM);
  SetHands(({({"mano izquierda",0,6}),({"mano derecha",0,6})}));
  SetAggressive(0);
  Set(P_CANT_FIGHT,"No puedes atacar a este ser incorp�reo.\n");

  InitChats(5,({"El sacerdote te dice: Cast�game mortal porque he pecado.\n",
		"El sacerdote dice: Esa mala criatura me traicion�... sisi me enga��...\n",
		"El sacerdote dice: Ella me decia que queria ver su cara. Yo no pens�...\n"}));

    AddQuestion(({"pecado"}),
  "El sacerdote se ara�a la piel mientras te dice en voz baja: Traicion� a mi dios.\n");

   AddQuestion(({"ella"}),
  "Izrun dice: Ella.. era una mujer de la noche.. pero yo no lo sabia\n"
  "lo juro, parec�a tan necesitada... tan enferma... que le ense�� la faz\n"
  "de mi dios.\n");

   AddQuestion(({"faz de Dehim","faz de dios"}),
  "Izrun te dice: Nos ayudar�s? si?\n"
  "- La estatuilla... ella me oll� rezar despu�s de mover la grande, y luego rez�\n"
  "las palabras para... entreg�rsela a su se�or!\n");

  AddQuestion(({"palabras","rezo"}),
  "El sacerdote te dice: Has de rezar a Dehim:\n"
  "Bondadoso Dehim abreme la puerta de tu casa\n");

  AddQuestion(({"grande"}),
  "El sacerdote deja de hacerte caso y grita mientras se golpea: Yo\n"
  "no lo sabia!!");

 AddQuestion(({"estatuilla", "estatua"}),
  "Era la viva imagen de nuestro dios. Es sagrada.\n"
  "Necesitamos esa figura para recuperar su gracia y est� escondida en\n"
  "alg�n lugar del templo.\n");
}
