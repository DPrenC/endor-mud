
#include <rooms.h>

#include <nightday.h>
#include <properties.h>
#include "path.h"

inherit ROOM;

create(){
  ::create();
  SetIndoors(0);
  SetLocate("bosqueDehim");
  SetIntSmell("Hueles a hierba fresca y a flores.\n");
  SetIntNoise("Escuchas el suave crujir de las ramas.\n");
  SetIntShort("el bosque de la Batalla Perdida");
  SetIntLong("El tronco caido de un �rbol reposa en el suelo. Tiene m�s a�os "
  		"que tu. Aparte de eso, no ves nada especial.\n");
  AddDetail(({"�rbol","arbol"}),"Est� quemado.\n");

  AddExit("oeste",ALULAGO("bosque/bosque1"));
  AddExit("suroeste",ALULAGO("bosque/bosque6"));
  AddExit("sur",ALULAGO("bosque/bosque7"));
  AddExit("este",ALULAGO("bosque/cam4"));
}
