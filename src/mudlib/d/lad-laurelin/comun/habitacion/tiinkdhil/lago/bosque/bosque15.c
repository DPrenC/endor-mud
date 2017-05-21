
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
  SetIntNoise("Escuchas el suave crujir de las ramas y el ruido de alg�n animal.\n");
  SetIntShort("el bosque de la Batalla Perdida");
  SetIntLong("Estas en un bosque. Desde aqui puedes ver la gran cordillera "
  		"que esconde el valle. Habias oido hablar de este sitio a viejos "
  		"enanos, pero nunca le diste cr�dito. Si mal no recuerdas sucedi� "
  		"algo tr�gico en esta zona. Al norte hay una casa peque�a.\n");
  AddDetail(({"cordillera"}),"Es alta y escarpada. No tiene vegetaci�n que la cubra.\n");

  AddItem(ALUOBJ("comida/menta"));

  AddExit("norte",ALULAGO("bosque/cabanya"));
  AddExit("noroeste",ALULAGO("bosque/bosque8"));
  AddExit("oeste",ALULAGO("bosque/bosque14"));
  AddExit("este",ALULAGO("bosque/bosque16"));
}
