/***************************************************************************************
 ARCHIVO:	casa_07.c
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
  SetIntLong("Est�s dentro de la casa. Es una casa confortable y familiar. "
  	"En las paredes hay varios retratos de personas. Hay una mesa y unas "
  	"sillas en el centro de la habitaci�n. Al fondo ves un armario y dos "
  	"camas.\n");

  AddDetail(({"pared"}),"En la pared hay varios retratos de personas.\n");
  AddDetail(({"retrato","pintura"}),"Es la pintura de una persona.\n");
  AddDetail(({"ventana"}),"Es una peque�a ventana que da a la plaza.\n");
  AddDetail(({"mesa"}),"Es una mesa de madera. Encima hay varios platos, vasos y cucharas.\n");
  AddDetail(({"cama"}),"Es una cama peque�a de madera.\n");
  AddDetail(({"vaso","vasos"}),"Hay varios vasos de madera. Est�n vacios y limpios.\n");
  AddDetail(({"cuchara"}),"Es una cuchara de madera.\n");
  AddDetail(({"suelo"}),"El suelo es de madera.\n");
  AddDetail(({"techo"}),"El techo es de paja, hay una lampara colgando de el.\n");
  AddDetail(({"lampara","l�mpara"}),"Es una l�mpara de aceite.\n");
  AddDetail(({"platos"}),"Son platos de barro. Est�n limpios y parecen nuevos.\n");

  AddExit("oeste",FLENHAB+"calles/plaza_01");
}