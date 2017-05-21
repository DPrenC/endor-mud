
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
  SetIntLong("En este lugar los �rboles son altos y algo de hierba cubre "
  		"el suelo. Est�s bordeando un bello edificio en ruinas.\n");

  SetIntSmell("Hueles a hierba fresca.\n");
  SetIntNoise("Escuchas el suave crujir de las ramas.\n");
  AddDetail(({"edificio"}),"Esta antigua estructura es la de un templo "
  		"dedicado a alg�n dios, tal vez �lfico ya que est�s en "
  		"Lad-Laurelin.\n");

  AddItem(ALUOBJ("comida/manzana"));

  AddExit("sur",ALULAGO("bosque/cabanya"));
}
