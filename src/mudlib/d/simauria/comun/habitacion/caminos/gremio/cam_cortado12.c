/****************************************************************************
Fichero: cam_cortado12.c
Autor: Ratwor
Fecha: 19/08/2007
Descripción: El camino entre montañas que se dirije a la cueva de los trolls.
****************************************************************************/


#include "./path.h"
#include <properties.h>
inherit CAMINOS "/gremio/cam_cortado_base";
create(){
    ::create();
    SetLocate("desfiladero de Marhalt");
    SetIntLong("   Te encuentras en una zigzagueante garganta que asciende internándose "
    " en las montañas.  La forma mas cómoda de avanzar es por la parte  mas profunda ,"
    " por donde corre un hilo de agua entre las peñas,  puesto que a ambos lados "
    "unas cortas pendientes , cubiertas de piedras sueltas  y arbustos, trepan "
    "rápidamente hasta adquirir la verticalidad y alzarse muchas decenas de metros."
    "\n A parte de la empobrecida vegetación y los furtivos escarceos, que surgen de "
    "los arbustos, no parece haber ninguna señal ni huella de otros animales. Es "
    "como si algo los hubiera ahuyentado de la zona, y tal vez ese algo siga rondando "
    "por las cercanías.\n En este punto el cañón se divide en dos. Del suroeste "
    "llega, escurriendose entre las rocas cubiertas de hierbajos, el pequeño curso "
    "de agua que recorre toda la garganta, mientras que al sudeste se extiende un "
    "gran amontonamiento de rocas.\n");

    AddExit("noroeste", "./cam_cortado11");
    AddExit("sureste", "./cam_cortado13");
    AddExit("suroeste", "./cam_cortado14");

}
