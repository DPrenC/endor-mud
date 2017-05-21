/*
Fichero: jardin1.c
Autor: aul�
Fecha: 04/08/2013
Descripci�n: Uno de los jardines de los hobbits.*/
#include "./path.h"
inherit HABITACION+"bree/base_aldea";
create()
{
    ::create();
    	SetIntShort("un peque�o jard�n");
    	SetIntLong(
    	"Aplanando una zona de la ladera de la colina y a un lado del camino que la "
    	"costea se ha extendido un peque�o jard�n de aspecto humilde y algo descuidado.\n"
    	"El c�sped llega a la rodilla escepto en el peque�o camino de gravilla que "
    	"conduce a la puerta del agujero hobbit situado justo al este. Un seto frondoso "
    	"cerca el jard�n pero no hay puerta alguna que cierre el paso, parece que el "
    	"due�o del lugar acepta visitas de buen grado.\n");
    AddExit("oeste", "./paseo5");
     AddExit("este", "/guilds/aventurero/sede/bree/aventurero");
     AddDoor("este", "una puerta redonda",
     "Es una puerta redonda, t�picamente hobbit. Est� hecha de s�lida madera pintada "
     "de verde y tiene una mirilla en el centro y un pomo de bronce para abrirla, junto a "
     "la cerradura.\n",
     ({"puerta verde", "redonda", "puerta redonda", "puerta", "este", "e", "puerta e", "puerta este"}));
     
    }