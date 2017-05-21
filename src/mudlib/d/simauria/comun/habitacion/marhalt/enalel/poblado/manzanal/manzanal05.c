/*

    Nombre      : manzanal05
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : Manzanal mágico del poblado
    
*/

#include "path.h"

inherit SIM_ROOM;
public int cmd_trepar(string str){
    if (!str || (str != "arbol" && str != "manzano" && str != "árbol" 
    && str != "al arbol" && str != "al manzano" && str != "al árbol")) return 0;
    write("El tronco del manzano es demasiado resbaladizo como para trepar por él.\n");
    return 1;
}

create() {
  ::create();

  SetIndoors(0);
  SetLocate("Poblado de Enalel");
  SetIntShort("el manzanal de Fhainfos");
  SetIntLong(W("Estás en el manzanal de Fhainfos. Los manzanos que aquí se "
  "pueden ver son más grandes y frondosos que cualquiera de los que hayas visto "
  "antes en tu vida. Hay senderos hacia el norte y el oeste.\n"));
  SetIntNoise("Un silencio mágico y tranquilizador se siente en este lugar.\n");
  SetIntSmell("El aroma de las manzanas parece mágico en este lugar.\n");
  AddDetail(({"suelo"}),"El suelo del manzanal está lleno de hojarasca.\n");
  AddDetail(({"manzano","manzanos","manzanal"}),W("Son unos enormes manzanos cuya "
  "corteza es dorada y sus frutos son más grandes que el resto."));
  AddDetail(({"manzana","manzanas","fruto","frutos"}),W("Las manzanas están muy "
  "altas, parecen muy grandes y jugosas.\n"));
  AddExit("norte",ENALHAB"poblado/manzanal/manzanal04");
  AddExit("oeste",ENALHAB"poblado/manzanal/manzanal06");
  AddRoomCmd("trepar","cmd_trepar");
}
