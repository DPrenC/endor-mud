/*

    Nombre      : calle08
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : Calle de la empalizada
    
*/
#include "path.h"
inherit SIM_ROOM;

create() {
  ::create();

  SetLocate("Poblado de Enalel");
  SetIntShort("la calle de la empalizada");
  SetIntLong(W("Estás en la calle de la empalizada. La empalizada que rodea "
  "todo el poblado se encuentra al norte y la parte trasera de las tiendas "
  "que dan a la calle del comercio están hacia el sur. La calle continúa al "
  "sudeste y al oeste.\n"));
  SetIndoors(0);
  SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
  SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
  AddDetail(({"suelo"}),"El suelo de arena está lleno de pisadas de los transeuntes.\n");
  AddDetail(({"pisada","pisadas"}),"Las pisadas van de un sitio a otro. Es imposible distinguir un rastro.\n");
  AddDetail(({"empalizada"}),"Es una empalizada de madera que rodea todo el poblado.\n");
  AddExit("sudeste",ENALHAB"poblado/calles/calle07");
  AddExit("oeste",ENALHAB"poblado/calles/calle09");
  AddItem(ENALPNJ"otros/pueblerino",REFRESH_DESTRUCT,1);
} 
