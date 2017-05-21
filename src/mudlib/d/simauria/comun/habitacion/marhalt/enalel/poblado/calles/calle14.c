/*

    Nombre      : calle14
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripci�n : Calle de las cosechas
    
*/
#include "path.h"
inherit SIM_ROOM;

create() {
  ::create();

  SetLocate("Poblado de Enalel");
  SetIntShort("la calle de las cosechas");
  SetIntLong(W("Est�s en la calle de las cosechas. Se pueden ver peque�os "
  "postes y estatuillas conmemorativas de cada una de las cosechas importantes. "
  "Hacia el nordeste est� el camino que lleva hacia la calle del comercio y la "
  "salida occidental del poblado. Hacia el suroeste contin�a la calle de las cosechas.\n"));
  SetIndoors(0);
  SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
  SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
  AddDetail(({"suelo"}),"El suelo de arena est� lleno de pisadas de los transeuntes.\n");
  AddDetail(({"pisada","pisadas"}),"Las pisadas van de un sitio a otro. Es imposible distinguir un rastro.\n");
  AddDetail(({"postes","poste","estatuillas","estatuilla"}),W("Son los s�mbolos que "
  "recuerdan algunas cosechas de gran calidad o haza�as de algunos h�roes locales.\n"));
  AddExit("nordeste",ENALHAB"poblado/calles/calle13");
  AddExit("suroeste",ENALHAB"poblado/calles/calle15");
} 
