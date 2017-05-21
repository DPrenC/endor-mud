/*

    Nombre      : calle14
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : Calle de las cosechas
    
*/
#include "path.h"
inherit SIM_ROOM;

create() {
  ::create();

  SetLocate("Poblado de Enalel");
  SetIntShort("la calle de las cosechas");
  SetIntLong(W("Estás en la calle de las cosechas. Se pueden ver pequeños "
  "postes y estatuillas conmemorativas de cada una de las cosechas importantes. "
  "Hacia el nordeste está el camino que lleva hacia la calle del comercio y la "
  "salida occidental del poblado. Hacia el suroeste continúa la calle de las cosechas.\n"));
  SetIndoors(0);
  SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
  SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
  AddDetail(({"suelo"}),"El suelo de arena está lleno de pisadas de los transeuntes.\n");
  AddDetail(({"pisada","pisadas"}),"Las pisadas van de un sitio a otro. Es imposible distinguir un rastro.\n");
  AddDetail(({"postes","poste","estatuillas","estatuilla"}),W("Son los símbolos que "
  "recuerdan algunas cosechas de gran calidad o hazañas de algunos héroes locales.\n"));
  AddExit("nordeste",ENALHAB"poblado/calles/calle13");
  AddExit("suroeste",ENALHAB"poblado/calles/calle15");
} 
