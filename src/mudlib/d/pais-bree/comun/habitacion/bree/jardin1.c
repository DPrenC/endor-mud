/*
Fichero: jardin1.c
Autor: aulë
Fecha: 04/08/2013
Descripción: Uno de los jardines de los hobbits.*/
#include "./path.h"
inherit HABITACION+"bree/base_aldea";
create()
{
    ::create();
    	SetIntShort("un pequeño jardín");
    	SetIntLong(
    	"Aplanando una zona de la ladera de la colina y a un lado del camino que la "
    	"costea se ha extendido un pequeño jardín de aspecto humilde y algo descuidado.\n"
    	"El césped llega a la rodilla escepto en el pequeño camino de gravilla que "
    	"conduce a la puerta del agujero hobbit situado justo al este. Un seto frondoso "
    	"cerca el jardín pero no hay puerta alguna que cierre el paso, parece que el "
    	"dueño del lugar acepta visitas de buen grado.\n");
    AddExit("oeste", "./paseo5");
     AddExit("este", "/guilds/aventurero/sede/bree/aventurero");
     AddDoor("este", "una puerta redonda",
     "Es una puerta redonda, típicamente hobbit. Está hecha de sólida madera pintada "
     "de verde y tiene una mirilla en el centro y un pomo de bronce para abrirla, junto a "
     "la cerradura.\n",
     ({"puerta verde", "redonda", "puerta redonda", "puerta", "este", "e", "puerta e", "puerta este"}));
     
    }