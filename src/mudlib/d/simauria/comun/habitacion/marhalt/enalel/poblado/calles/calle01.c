/*

    Nombre      : calle01
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : Entrada desde el sendero del Pomar
    
*/
#include "path.h"
inherit SIM_ROOM;

create() {
  ::create();

  SetLocate("Poblado de Enalel");
  SetIntShort("la entrada del poblado de Enalel");
  SetIntLong(W("Estás en la entrada de Enalel. Aquí, una garita situada junto a la "
  "empalizada, sirve a la guardia de Enalel como punto para controlar quien entra y "
  "sale del poblado. Al oeste comienza la calle del comercio y al este está el sendero "
  "del Pomar.\n"));
  SetIndoors(0);
  SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
  SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
  AddDetail(({"suelo"}),"El suelo de arena está lleno de pisadas de los transeuntes.\n");
  AddDetail(({"garita","garita de la guardia"}),W("La garita de la guardia es una pequeña "
  "construcción adosada a la empalizada.\n"));
  AddDetail(({"pisada","pisadas"}),"Las pisadas van de un sitio a otro. Es imposible distinguir un rastro.\n");
  AddExit("este",POMARHAB"sendero21");
  AddExit("oeste",ENALHAB"poblado/calles/calle02");
  AddItem(ENALPNJ"guardias/sargento",REFRESH_DESTRUCT,1);
  AddItem(ENALPNJ"guardias/enalel",REFRESH_DESTRUCT,1);
} 
