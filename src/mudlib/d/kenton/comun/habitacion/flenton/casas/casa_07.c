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
  SetIntLong("Estás dentro de la casa. Es una casa confortable y familiar. "
  	"En las paredes hay varios retratos de personas. Hay una mesa y unas "
  	"sillas en el centro de la habitación. Al fondo ves un armario y dos "
  	"camas.\n");

  AddDetail(({"pared"}),"En la pared hay varios retratos de personas.\n");
  AddDetail(({"retrato","pintura"}),"Es la pintura de una persona.\n");
  AddDetail(({"ventana"}),"Es una pequeña ventana que da a la plaza.\n");
  AddDetail(({"mesa"}),"Es una mesa de madera. Encima hay varios platos, vasos y cucharas.\n");
  AddDetail(({"cama"}),"Es una cama pequeña de madera.\n");
  AddDetail(({"vaso","vasos"}),"Hay varios vasos de madera. Están vacios y limpios.\n");
  AddDetail(({"cuchara"}),"Es una cuchara de madera.\n");
  AddDetail(({"suelo"}),"El suelo es de madera.\n");
  AddDetail(({"techo"}),"El techo es de paja, hay una lampara colgando de el.\n");
  AddDetail(({"lampara","lámpara"}),"Es una lámpara de aceite.\n");
  AddDetail(({"platos"}),"Son platos de barro. Están limpios y parecen nuevos.\n");

  AddExit("oeste",FLENHAB+"calles/plaza_01");
}