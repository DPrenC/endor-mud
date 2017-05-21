/*

    Nombre      : manzanal01
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripci�n : Manzanal m�gico del poblado
    
*/

#include "path.h"

inherit SIM_ROOM;

public int cmd_trepar(string str){
    if (!str || (str != "arbol" && str != "manzano" && str != "�rbol" 
    && str != "al arbol" && str != "al manzano" && str != "al �rbol")) return 0;
    write("El tronco del manzano es demasiado resbaladizo como para trepar por �l.\n");
    return 1;
}

create() {
  ::create();
  
  SetIndoors(0);
  SetLocate("Poblado de Enalel");
  SetIntShort("el manzanal de Fhainfos");
  SetIntLong(W("Est�s en un peque�o manzanal conocido como el manzanal de fhainfos, "
  "ya que es aqu� donde crecieron los primeros manzanos de Enalel. Los manzanos que "
  "aqu� se pueden ver son m�s grandes y frondosos que cualquiera de los que hayas "
  "visto antes en tu vida. Una extra�a sensaci�n te hace pensar que un aire m�gico "
  "se respira en el ambiente. Hay senderos hacia el sur y el oeste. Al este est� el "
  "puente de Enalel.\n"));
  SetIntNoise("Un silencio m�gico y tranquilizador se siente en este lugar.\n");
  SetIntSmell("El aroma de las manzanas parece m�gico en este lugar.\n");
  AddDetail(({"suelo"}),"El suelo del manzanal est� lleno de hojarasca.\n");
  AddDetail(({"manzano","manzanos","manzanal"}),W("Son unos enormes manzanos cuya "
  "corteza es dorada y sus frutos son m�s grandes que el resto."));
  AddDetail(({"manzana","manzanas","fruto","frutos"}),W("Las manzanas est�n muy altas, "
  "parecen muy grandes y jugosas.\n"));
  AddExit("este",ENALHAB"poblado/varios/puente");
  AddExit("oeste",ENALHAB"poblado/manzanal/manzanal02");
  AddExit("sur",ENALHAB"poblado/manzanal/manzanal04");
  AddRoomCmd("trepar","cmd_trepar");
}
