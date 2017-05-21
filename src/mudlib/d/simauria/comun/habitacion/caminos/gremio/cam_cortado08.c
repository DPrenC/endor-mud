/****************************************************************************
Fichero: cam_cortado08.c
Autor: Ratwor
Fecha: 19/08/2007
Descripci�n: El camino entre las monta�as que se dirije a las cuevas de los trolls.
****************************************************************************/


#include "./path.h"
#include <properties.h>
inherit CAMINOS "/gremio/cam_cortado_base";
create(){
    ::create();
    SetLocate("desfiladero de Marhalt");
    SetIntLong("   Te encuentras en una zigzagueante garganta que asciende intern�ndose "
    " en las monta�as.  La forma mas c�moda de avanzar es por la parte  mas profunda , "
    "por donde corre un hilo de agua entre las pe�as,  puesto que a ambos lados unas "
    "cortas pendientes , cubiertas de piedras sueltas  y arbustos, trepan r�pidamente "
    "hasta adquirir la verticalidad y alzarse muchas decenas de metros.\n A parte de "
    "la empobrecida vegetaci�n y los furtivos escarceos, que surgen de los arbustos, "
    "no parece haber ninguna se�al ni huella de otros animales. Es como si algo los "
    "hubiera ahuyentado de la zona, y tal vez ese algo siga rondando por las cercan�as.\n");
    AddExit("sureste", "./cam_cortado07");
    AddExit("noreste", "./cam_cortado09");
}
