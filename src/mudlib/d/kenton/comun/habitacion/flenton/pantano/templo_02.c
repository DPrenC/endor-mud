/***************************************************************************************
 ARCHIVO:	templo_02.c
 AUTOR:		[k] Korsario
 FECHA:		13-11-1998
 COMENTARIOS:	Templo en el pantano de la muerte
 ***************************************************************************************/

#include "path.h"

inherit ROOM;

create() {
  ::create();

  SetIndoors(1);
  SetIntBright(40);
  SetLocate("pantano de la muerte");
  SetIntNoise("Escuchas los lamentos que trae el viento, gritos de agonía, el dolor "
  	"de los no muertos...\n");
  SetIntSmell("Huele fatal aquí, como a algo podrido.\n");

  SetIntShort("el templo del pantano de la muerte");
  SetIntLong("Estás en la cámara principal del templo.\n");

  AddDetail(({"paredes", "moho","suciedad"}),"Las paredes están repletas de moho "
	"y suciedad.\n");
  AddDetail(({"huesos","restos"}),"El suelo está repleto de huesos de seres de "
  	"todos los tamaños.\n");

  AddExit("sur",FLENHAB+"pantano/templo_01");
  AddItem(FLENPNJ+"pantano/espectro",REFRESH_DESTRUCT);
}