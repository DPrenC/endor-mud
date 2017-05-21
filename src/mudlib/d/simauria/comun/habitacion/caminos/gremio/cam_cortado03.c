/****************************************************************************
Fichero: cam_cortado03.c
Autor: Ratwor
Fecha: 19/08/2007
Descripción: El camino que va a psionicos y cueva de los trolls.
****************************************************************************/


#include "./path.h"

inherit CAMINOS "/gremio/cam_cortado_base";
create() {
    ::create();
    SetIntLong("   Te encuentras en un zigzagueante desfiladero que se interna en las "
    "montañas.  La forma mas cómoda de avanzar es por la parte mas profunda  puesto "
    "que a ambos lados unas cortas pendientes  cubiertas de piedras sueltas  y arbustos "
    "trepan rápidamente hasta adquirir la verticalidad y alzarse muchas decenas de "
    "metros.\n A parte de la empobrecida vegetación y los furtivos escarceos que "
    "surgen de ella, de vez en cuando, no parece haber ninguna señal ni huella de otros "
    "animales. Parece como si algo los hubiera ahuyentado de la zona, y tal vez "
    "ese algo siga rondando por las cercanías.\n Al norte puedes ver, entre dos "
    "grandes contrafuertes, el inicio de otra garganta que se interna aún mas en "
    "las montañas, mientras que hacia el este y el oeste se extiende el desfiladero "
    "principal.\n");
    AddDetail(({"garganta", "otra garganta", "inicio", "norte"}),
    "Al norte y flanqueada, como si de una puerta natural se tratara, por dos grandes "
    "contrafuertes de roca, puedes ver  una pedregosa garganta que asciende entre "
    "rocosas paredes. \n  Un hilo de agua gotea, perezosamente por el fondo, sobre "
    "algunos escalones naturales para formar un pequeño charco al pie de uno de "
    "los contrafuertes.\n");
    AddDetail(({"charco", "agua", "charca", "hilo de agua", "hilo", "sucia charca"}),
    "Tras descender del norte, el agua de color pardusco se deposita al pie del "
    "contrafuerte occidental formando una sucia charca que se extiende bajo los "
    "arbustos espinosos y la maleza, que gracias a ello presenta un color mas vivo.\n");
    AddExit("este", "./cam_cortado02");
    AddExit("oeste", "./cam_cortado04");
    AddExit("norte", "./cam_cortado07");
}
