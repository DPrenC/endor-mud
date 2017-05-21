/****************************************************************************
Fichero: cam_cortado01.c
Autor: Ratwor
Fecha: 19/08/2007
Descripci�n: El camino entre las monta�as que se dirije a psionicos y cuevas de los trolls.
****************************************************************************/


#include "./path.h"
inherit CAMINOS "/gremio/cam_cortado_base";
create() {
    ::create();
    SetIntLong(" La garganta del sudeste da paso aqu� a un zigzagueante desfiladero "
    "algo mas ancho que se interna en las monta�as.  La forma mas c�moda de avanzar es "
    "por la parte mas baja, puesto que a ambos lados unas cortas pendientes  cubiertas "
    "de piedras sueltas  y arbustos trepan r�pidamente hasta adquirir la verticalidad "
    "y alzarse muchas decenas de metros.\n A parte de la empobrecida vegetaci�n y "
    "los furtivos escarceos que surgen de ella de vez en cuando, no parece haber "
    "ninguna se�al ni huella de otros animales. Parece como si algo los hubiera "
    "ahuyentado de la zona, y tal vez ese algo siga rondando por las cercan�as.\n"
     "Hacia el sureste se puede ver la garganta que se abre sobre el camino y por "
     "el noroeste contin�a el desfiladero.\n");

    AddExit("sureste", "./cam_cortado00");
    AddExit("noroeste", "./cam_cortado02");
}
