/****************************************************************************
Fichero: cam_cortado01.c
Autor: Ratwor
Fecha: 19/08/2007
Descripción: El camino entre las montañas que se dirije a psionicos y cuevas de los trolls.
****************************************************************************/


#include "./path.h"
inherit CAMINOS "/gremio/cam_cortado_base";
create() {
    ::create();
    SetIntLong(" La garganta del sudeste da paso aquí a un zigzagueante desfiladero "
    "algo mas ancho que se interna en las montañas.  La forma mas cómoda de avanzar es "
    "por la parte mas baja, puesto que a ambos lados unas cortas pendientes  cubiertas "
    "de piedras sueltas  y arbustos trepan rápidamente hasta adquirir la verticalidad "
    "y alzarse muchas decenas de metros.\n A parte de la empobrecida vegetación y "
    "los furtivos escarceos que surgen de ella de vez en cuando, no parece haber "
    "ninguna señal ni huella de otros animales. Parece como si algo los hubiera "
    "ahuyentado de la zona, y tal vez ese algo siga rondando por las cercanías.\n"
     "Hacia el sureste se puede ver la garganta que se abre sobre el camino y por "
     "el noroeste continúa el desfiladero.\n");

    AddExit("sureste", "./cam_cortado00");
    AddExit("noroeste", "./cam_cortado02");
}
