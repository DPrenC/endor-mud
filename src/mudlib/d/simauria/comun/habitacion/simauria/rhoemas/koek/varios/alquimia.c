/***************************************************************************************
 ARCHIVO:	alquimia.c
 AUTOR:		[z] Zomax
 FECHA:		27-04-2003
 COMENTARIOS:	La casa del alquimista.
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;
#include RHOEPRESO

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(50);
  SetLocate("Koek");
  SetIntShort("la casa del alquimista");
  SetIntSmell(W("Huele indescriptiblemente... ni mal ni bien, únicamente no sabes a qué "
  	"huele.\n"));
  SetIntNoise("No oyes nada especial.\n");
  SetIntLong(W("Estás en una casa que más que casa parece un taller, ves máquinas extrañas "
  	"por todas partes como si fuera la forja de un inventor enano y piezas de metal "
  	"tiradas por el suelo. Bajo la chimenea hay un gran caldero con metal fundido "
  	"y unos bonitos cristales de colores.\n"));
  
  AddDetail(({"maquina","máquina","maquinas","máquinas"}),W("Son de lo más extraño aunque "
  	"te parece que la mitad ni funciona, simplemente hacen de este lugar algo exótico.\n"));
  AddDetail(({"piezas de metal","pieza de metal"}),W("Ves tiradas por todos lados muchas "
  	"partes de máquinas que se han ido gastando o rompiendo en los experimentos.\n"));
  AddDetail(({"suelo"}),"Este lugar está bastante desordenado.\n");
  AddDetail(({"chimenea"}),W("Hay una gran chimenea en una de las paredes con un caldero "
  	"en ella.\n"));
  AddDetail(({"caldero"}),W("Parece que el dueño de la cabaña se dedica a fundir metales "
  	"aquí...\n"));
  AddDetail(({"cristales","cristales de colores"}),W("Ves tu reflejo en ellos, son muy "
  	"bonitos pero no valen nada, si aún fueran gemas...\n"));
  
  carcel=(RHOEHAB("koek/calles/cendaf_05"));
  AddExit("este",RHOEHAB("koek/calles/cendaf_05"));
  AddItem(RHOEPNJ("koek/varios/kamui"),REFRESH_DESTRUCT,1);
}
