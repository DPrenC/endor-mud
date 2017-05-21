/***************************************************************************************
 ARCHIVO:	jefe_02.c
 AUTOR:		[k] Korsario
 FECHA:		27-02-1998
 COMENTARIOS:	Calle del Jefe
 ***************************************************************************************/

#include "path.h"

inherit ROOM;

create() {
  ::create();

  SetIndoors(0);
  SetLocate("flenton");
  SetIntNoise("Escuchas voces y risas.\n");
  SetIntSmell("Te llega el aroma de comida. Alguien debe estar preparando algo.\n");

  SetIntShort("la calle del Jefe");
  SetIntLong("Este es el extremo este de la Calle del Jefe. Mirando hacia "
  	"el centro del poblado divisas el Gran Árbol. Hacia el norte y el sur "
  	"hay pequeñas casas hechas de barro y paja. La calle continúa hacia el "
  	"oeste, y hacia el este esta la puerta de entrada del poblado.\n");

  AddDetail(({"arbol","árbol"}),"A lo lejos ves un gran árbol que sobresale "
  	"en el medio del poblado.\n");
  AddDetail(({"casa"}),"Es una casa pequeña con dos ventanas. Esta hecha de "
  	"barro y piedras, y el tejado es de paja. No tiene puerta, solo una "
  	"cortina impide ver el interior.\n");

  AddExit("norte",FLENHAB+"casas/casa_01");
  AddExit("sur",FLENHAB+"casas/casa_03");
  AddExit("oeste",FLENHAB"calles/jefe_01");
  AddExit("este",FLENHAB+"calles/entrada");
  AddItem(FLENPNJ+"poblado/hombre",REFRESH_DESTRUCT);
}