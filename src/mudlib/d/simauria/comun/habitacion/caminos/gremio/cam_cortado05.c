/****************************************************************************
Fichero: cam_cortado05.c
Autor: Ratwor
Fecha: 19/08/2007
Descripción: El camino entre las montañas que lleva a psionicos y a la cueva de los trolls.
****************************************************************************/

#include "./path.h"

inherit CAMINOS "/gremio/cam_cortado_base";
create() {
    ::create();
    SetIntLong("   Te encuentras en un zigzagueante desfiladero que se interna en las "
    "montañas.  La forma mas cómoda de avanzar es por la parte mas profunda  puesto que"
    " a ambos lados, unas cortas pendientes  cubiertas de piedras sueltas  y arbustos"
    ", trepan rápidamente hasta adquirir la verticalidad y alzarse muchas decenas de "
    "metros.\n A parte de la empobrecida vegetación y los furtivos escarceos que surgen "
    "de ella de vez en cuando, no parece haber ninguna señal ni huella de otros "
    "animales. Parece como si algo los hubiera ahuyentado de la zona, y tal vez "
    "ese algo siga rondando por las cercanías.\n Hacia el oeste divisas lo que parece "
    "ser el término del desfiladero, pues éste se abre a un terreno lleno de espesas "
    "malezas.\n");

    AddExit("sureste", "./cam_cortado04");
    AddExit("oeste", "./cam_cortado06");
}
