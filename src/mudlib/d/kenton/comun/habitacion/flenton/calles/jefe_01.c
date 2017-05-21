/***************************************************************************************
 ARCHIVO:	jefe_01.c
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
  SetIntSmell("No hueles nada en especial.\n");

  SetIntShort("la calle del Jefe");
  SetIntLong("Estás en la Calle del Jefe. Mirando hacia el centro del poblado "
  	"divisas el Gran Árbol. Hacia el norte y el sur hay pequeñas casas hechas "
  	"de barro y paja. La calle termina continua hacia el oeste y hacia el este.\n");

  AddDetail(({"arbol","árbol"}),"A lo lejos ves un gran árbol que sobresale en "
  	"el medio del poblado.\n");
  AddDetail(({"casa"}),"Es una casa pequeña con dos ventanas. Está hecha de "
  	"barro y piedras, y el tejado es de paja.\n");

  AddExit("norte",FLENHAB+"casas/casa_02");
  AddExit("sur",FLENHAB+"casas/casa_04");
  AddExit("oeste",FLENHAB+"calles/jefe_02");
  AddExit("este",FLENHAB+"calles/jefe_00");
  AddItem(FLENPNJ+"poblado/ninyo",REFRESH_DESTRUCT,1);
}