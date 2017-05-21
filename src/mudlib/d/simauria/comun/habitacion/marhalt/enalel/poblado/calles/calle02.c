/*

    Nombre      : calle02
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : Calle del comercio
    
*/
#include "path.h"
inherit SIM_ROOM;

create() {
  ::create();

  SetLocate("Poblado de Enalel");
  SetIntShort("un cruce de calles");
  SetIntLong(W("Estás en la calle del comercio. Aquí encontrarás mercancías "
  "relacionadas con el principal producto de Enalel: las manzanas. La calle "
  "continúa hacia el oeste. Al norte comienza la calle de la empalizada y al "
  "sur la calle de las cosechas.\n"));
  SetIndoors(0);
  SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
  SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
  AddDetail(({"suelo"}),"El suelo de arena está lleno de pisadas de los transeuntes.\n");
  AddDetail(({"pisada","pisadas"}),W("Las pisadas van de un sitio a otro. Es "
  "imposible distinguir un rastro.\n"));
  AddExit("este",ENALHAB"poblado/calles/calle01");
  AddExit("oeste",ENALHAB"poblado/calles/calle03");
  AddExit("norte",ENALHAB"poblado/calles/calle07");
  AddExit("sur",ENALHAB"poblado/calles/calle13");
  AddItem(ENALPNJ"otros/pueblerino",REFRESH_DESTRUCT,1);
} 