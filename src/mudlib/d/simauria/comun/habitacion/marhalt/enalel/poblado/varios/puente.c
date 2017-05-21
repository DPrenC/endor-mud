/*

    Nombre      : puenteEnalel
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripci�n : Paso entre el poblado y el manzanal de Fhainfos
    
*/

#include "path.h"

inherit SIM_ROOM;

create() {
  ::create();

  SetLocate("Poblado de Enalel");
  SetIntShort("el puente de Enalel");
  SetIntLong(W("Est�s sobre un fuerte puente de madera que cruza el r�o pomohs uniendo el "
  "poblado de Enalel con el peque�o manzanar de Fhainfos.\n"
  "El puente cruza de este a oeste.\n"));
  SetIndoors(0);
  SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
  SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
  AddDetail(({"suelo"}),"el suelo de arena est� lleno de pisadas de los transeuntes.\n");
  AddDetail(({"pisada","pisadas"}),"Las pisadas van de un sitio a otro. Es imposible distinguir un rastro.\n");
  AddExit("este",ENALHAB"poblado/calles/calle22");
  AddExit("oeste",ENALHAB"poblado/manzanal/manzanal01");
}
