/***************************************************************************************
 ARCHIVO:	sendero_01.c
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
  SetIntLong("Es un sinuoso sendero que continúa hacia el nordeste, "
  	"dirección en la cual ves una curiosa casa de madera. A ambos "
  	"lados del camino hay jardines con flores y hierbas de todos los "
  	"tamaños. El sendero también sigue hacia el sudeste.\n");

  AddDetail(({"arbol","árbol"}),"A lo lejos ves un gran árbol que "
  	"sobresale en el medio del poblado.\n");
  AddDetail(({"casa"}),"Ves a lo lejos una curiosa casa de madera.\n");
  AddDetail(({"jardin","jardín","jardines"}),"Hay jardines bordeando el "
  	"sendero a ambos lados. Hay infinidad de flores y plantas que nunca "
  	"antes habias visto. Te preguntas quién las pudo haber plantado.\n");

  AddExit("nordeste",FLENHAB+"calles/sendero_02");
  AddExit("sudeste",FLENHAB+"calles/sendero_00");
}