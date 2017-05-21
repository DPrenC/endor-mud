
#include <rooms.h>
#include <nightday.h>
#include <properties.h>
#include "path.h"

inherit ROOM;

create(){
  ::create();
  SetIndoors(0);
  SetLocate("bosqueDehim");
  SetIntShort("el bosque de la Batalla Perdida");
  SetIntLong("La vegetación se abre ante ti para mostrarte un magnífico "
  		"edificio caído por alguna guerra.\n");
  SetIntSmell("Hueles a hierba fresca y a flores.\n");
  SetIntNoise("Escuchas el suave crujir de las ramas.\n");
  AddDetail(({"edificio"}),"Esta antigua estructura es la de un templo "
  		"dedicado a algún dios, tal vez élfico ya que estás en "
  		"Lad-Laurelin.\n");

  AddExit("sur",ALULAGO("bosque/bosque10"));
}
