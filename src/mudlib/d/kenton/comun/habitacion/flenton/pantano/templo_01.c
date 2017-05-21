/***************************************************************************************
 ARCHIVO:	templo_01.c
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
  SetIntNoise("Escuchas los lamentos que trae el viento, gritos de agon�a, el "
  	"dolor de los no muertos...\n");
  SetIntSmell("Huele fatal aqu�, como a algo podrido.\n");

  SetIntShort("el templo del pantano de la muerte");
  SetIntLong("Est�s dentro del templo. Las paredes est�n llenas de moho y "
  	"suciedad. A ambos lados hay dos pasillos que han quedado obstruidos "
  	"por piedras que han ca�do del techo. El suelo est� lleno de huesos y "
  	"restos de otros que pisaron esta estancia antes que t� y que no "
  	"corrieron buena suerte. Hacia el norte ves la entrada a una estancia "
  	"mas amplia donde se ve un leve resplandor.\n");

  AddDetail(({"paredes", "moho","suciedad"}),"Las paredes est�n repletas de "
  	"moho y suciedad.\n");
  AddDetail(({"huesos","restos"}),"El suelo est� repleto de huesos de seres "
  	"de todos los tama�os.\n");

  AddExit("norte",FLENHAB+"pantano/templo_02");
}