/****************************************************************************
Fichero: cam_cortado09.c
Autor: Ratwor
Fecha: 19/08/2007
Descripci�n: El camino entre monta�as que se dirije a la cueva de los trolls.
****************************************************************************/


#include "./path.h"
#include <properties.h>
inherit CAMINOS "/gremio/cam_cortado_base";

create(){
    ::create();
    SetLocate("desfiladero de Marhalt");
    SetIntLong("   Te encuentras en una zigzagueante garganta que asciende intern�ndose "
    " en las monta�as.  La forma mas c�moda de avanzar es por la parte  mas profunda ,"
    " por donde corre un hilo de agua entre las pe�as,  puesto que a ambos lados unas "
    "cortas pendientes , cubiertas de piedras sueltas  y arbustos, trepan r�pidamente "
    "hasta adquirir la verticalidad y alzarse muchas decenas de metros.\n A parte de "
    "la empobrecida vegetaci�n y los furtivos escarceos, que surgen de los arbustos, "
    "no parece haber ninguna se�al ni huella de otros animales. Es como si algo los "
    "hubiera ahuyentado de la zona, y tal vez ese algo siga rondando por las cercan�as."
    "\n Aqu� una afilada arista de roca, como la proa de un barco, divide el ca��n en "
    "dos. Hacia el noroeste el desfiladero parece terminar frente a una pared cortada a "
    "pico, mientras que al nordeste sigue ascendiendo.\n");

    AddExit("suroeste", "./cam_cortado08");
    AddExit("nordeste", "./cam_cortado10");
    AddExit("noroeste", "./cam_cortado15");

}
