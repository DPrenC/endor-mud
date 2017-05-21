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
  SetIntSmell(W("Huele indescriptiblemente... ni mal ni bien, �nicamente no sabes a qu� "
  	"huele.\n"));
  SetIntNoise("No oyes nada especial.\n");
  SetIntLong(W("Est�s en una casa que m�s que casa parece un taller, ves m�quinas extra�as "
  	"por todas partes como si fuera la forja de un inventor enano y piezas de metal "
  	"tiradas por el suelo. Bajo la chimenea hay un gran caldero con metal fundido "
  	"y unos bonitos cristales de colores.\n"));
  
  AddDetail(({"maquina","m�quina","maquinas","m�quinas"}),W("Son de lo m�s extra�o aunque "
  	"te parece que la mitad ni funciona, simplemente hacen de este lugar algo ex�tico.\n"));
  AddDetail(({"piezas de metal","pieza de metal"}),W("Ves tiradas por todos lados muchas "
  	"partes de m�quinas que se han ido gastando o rompiendo en los experimentos.\n"));
  AddDetail(({"suelo"}),"Este lugar est� bastante desordenado.\n");
  AddDetail(({"chimenea"}),W("Hay una gran chimenea en una de las paredes con un caldero "
  	"en ella.\n"));
  AddDetail(({"caldero"}),W("Parece que el due�o de la caba�a se dedica a fundir metales "
  	"aqu�...\n"));
  AddDetail(({"cristales","cristales de colores"}),W("Ves tu reflejo en ellos, son muy "
  	"bonitos pero no valen nada, si a�n fueran gemas...\n"));
  
  carcel=(RHOEHAB("koek/calles/cendaf_05"));
  AddExit("este",RHOEHAB("koek/calles/cendaf_05"));
  AddItem(RHOEPNJ("koek/varios/kamui"),REFRESH_DESTRUCT,1);
}
