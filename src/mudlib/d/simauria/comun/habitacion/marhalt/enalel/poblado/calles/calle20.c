/*

    Nombre      : calle20
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : Calle del manzanar
    
*/
#include "path.h"
inherit SIM_ROOM;

create() {
  ::create();

  SetLocate("Poblado de Enalel");
  SetIntShort("la calle del manzanar");
  SetIntLong(W("Estás en la calle del manzanar. La calle transcurre de nordeste "
  "a oeste. Al sur empieza el camino de la meditación.\n"));
  SetIndoors(0);
  SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
  SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
  AddDetail(({"suelo"}),"El suelo de arena está lleno de pisadas de los transeuntes.\n");
  AddDetail(({"pisada","pisadas"}),"Las pisadas van de un sitio a otro. Es imposible distinguir un rastro.\n");
  AddExit("nordeste",ENALHAB"poblado/calles/calle19");
  AddExit("oeste",ENALHAB"poblado/calles/calle21");
  AddExit("sur",ENALHAB"poblado/calles/calle23");
} 
