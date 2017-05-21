
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
  SetIntNoise("Escuchas el suave crujir de las ramas. Un gorrión canta feliz.\n");
  SetIntShort("el bosque de la Batalla Perdida");
  SetIntLong("En este sitio abundan los arbustos mediantos, y árboles "
  		"tan singulares como son los sauces llorones. Hay tanta "
  		"vegetación que te cuesta moverte entre ella.\n");

  AddExit("sur",ALULAGO("bosque/lago1"));
  AddExit("oeste",ALULAGO("bosque/bosque16"));
  HideExit("sur",1);
}
