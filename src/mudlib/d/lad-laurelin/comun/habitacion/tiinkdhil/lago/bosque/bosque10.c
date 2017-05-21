
#include <rooms.h>

#include <nightday.h>
#include <properties.h>
#include "path.h"

inherit ROOM;

create(){
  ::create();
  SetIndoors(0);
  SetLocate("bosqueDehim");
  SetIntSmell("Huele a hierba fresca y a flores.\n");
  SetIntNoise("Escuchas el suave crujir de las ramas.\n");
  SetIntShort("el bosque de la Batalla Perdida");
  SetIntLong("Hay tierra y árboles diversos. Este bosque es un poco raro. No sabes "
  		"por qué pero te lo parece. Ves algunas casas cerca.\n");
  AddDetail(({"arboles","árboles"}),"Son árboles medianos de hoja caduca. Uno de "
  		"ellos está muy ladeado, y sus largas ramas tocan el suelo.\n");
  AddDetail(({"arbol ladeado","árbol ladeado"}),"Parece que tapa algo... Urgas un poco?\n");

  AddExit("norte",ALULAGO("bosque/bosque4"));
  AddExit("este",ALULAGO("bosque/casita"));
  AddExit("oeste",ALULAGO("bosque/cabanya"));
}
