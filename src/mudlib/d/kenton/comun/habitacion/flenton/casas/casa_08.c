/***************************************************************************************
 ARCHIVO:	casa_08.c
 AUTOR:		[k] Korsario
 FECHA:		28-02-1998
 COMENTARIOS:	Casa de un kender
 ***************************************************************************************/

#include "path.h"

inherit ROOM;

create(){
  ::create();

  SetIndoors(1);
  SetIntBright(80);
  SetLocate("flenton");
  SetIntNoise("Escuchas el rumor de la calle.\n");
  SetIntSmell("Huele a limpio.\n");

  SetIntShort("una casa de la plaza Kendarg");
  SetIntLong("Est�s dentro de la casa. Est� totalmente vacia, pero limpia. "
  	"Quiz�s espera a un nuevo propietario.\n");

  AddDetail(({"pared"}),"La pared esta limpia y sin adornos.\n");
  AddDetail(({"ventana"}),"Es una peque�a ventana que da a la plaza.\n");
  AddDetail(({"suelo"}),"El suelo es de madera.\n");
  AddDetail(({"techo"}),"El techo es de paja.\n");

  AddExit("sur",FLENHAB+"calles/plaza_01");
}