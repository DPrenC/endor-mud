/****************************************************************************
Fichero: cam_cortado05.c
Autor: Ratwor
Fecha: 19/08/2007
Descripci�n: El camino entre las monta�as que lleva a psionicos y a la cueva de los trolls.
****************************************************************************/

#include "./path.h"

inherit CAMINOS "/gremio/cam_cortado_base";
create() {
    ::create();
    SetIntLong("   Te encuentras en un zigzagueante desfiladero que se interna en las "
    "monta�as.  La forma mas c�moda de avanzar es por la parte mas profunda  puesto que"
    " a ambos lados, unas cortas pendientes  cubiertas de piedras sueltas  y arbustos"
    ", trepan r�pidamente hasta adquirir la verticalidad y alzarse muchas decenas de "
    "metros.\n A parte de la empobrecida vegetaci�n y los furtivos escarceos que surgen "
    "de ella de vez en cuando, no parece haber ninguna se�al ni huella de otros "
    "animales. Parece como si algo los hubiera ahuyentado de la zona, y tal vez "
    "ese algo siga rondando por las cercan�as.\n Hacia el oeste divisas lo que parece "
    "ser el t�rmino del desfiladero, pues �ste se abre a un terreno lleno de espesas "
    "malezas.\n");

    AddExit("sureste", "./cam_cortado04");
    AddExit("oeste", "./cam_cortado06");
}
