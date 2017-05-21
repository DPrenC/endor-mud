/***************************************************************************************
 ARCHIVO:	sendero_00.c
 AUTOR:		[k] Korsario
 FECHA:		27-02-1998
 COMENTARIOS:	Sendero que lleva a casa del Shamán
 ***************************************************************************************/

#include "path.h"

inherit ROOM;

create() {
  ::create();

  SetIndoors(0);
  SetLocate("flenton");
  SetIntNoise("Oyes el canto de los pajaros.\n");
  SetIntSmell("Huele a hierbabuena y otras hierbas olorosas.\n");

  SetIntShort("el sendero del Shamán");
  SetIntLong("Es un sinuoso sendero que continúa hacia el norte. A ambos "
  	"lados hay jardines con flores y hierbas de todos los tamaños. Al este, "
  	"a lo lejos, divisas el centro del poblado, y el gran árbol sobresaliendo "
  	"de entre las casas. Al sur está la calle Kendarg.\n");

  AddDetail(({"arbol","árbol"}),"A lo lejos ves un gran árbol que sobresale "
  	"en el medio del poblado.\n");
  AddDetail(({"sendero"}),"Un sinuoso sendero se aleja hacia el norte.\n");
  AddDetail(({"jardin","jardines"}),"Hay jardines bordeando el sendero a ambos "
  	"lados. Hay infinidad de flores y plantas que nunca antes habias visto. Te "
  	"preguntas quien las pudo haber plantado.\n");

  AddExit("noroeste",FLENHAB+"calles/sendero_01");
  AddExit("sur",FLENHAB+"calles/kendarg_04");
}