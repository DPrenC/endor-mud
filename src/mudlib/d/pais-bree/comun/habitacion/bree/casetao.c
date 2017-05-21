/*
Fichero: casetao.c
Autor: aulë
Fecha: 12/03/2013
Descripción: caseta de guardia para los vigilantes de la puerta oeste. 
*/
#include "./path.h"
inherit BREE_ROOM;
create()
{
    ::create();
    	SetIntShort("Una caseta de guardia");
    	    SetIndoors(1);
    SetIntBright(20);
    SetIntShort("caseta de guardia");
    SetIntLong("El interior de la caseta de guardia consta de una pequeña estancia "
    "con muros de piedra sin desvastar, suelo de tierra batida y techo a dos aguas "
    "sustentado por vigas de madera.\n"
    "En una de las paredes se sitúa un hogar de piedra y una serie de ganchos se "
    "alinean en la pared opuesta.\n"
    "Frente a la puerta y apoyada contra la pared hay una tarima de madera para que el "
    "vigilante descanse cuando así se lo permitan sus obligaciones.\n"
    "Junto al hogar hay un par de toscos taburetes.\n");
    AddDetail(({"taburete", "taburetes"}),
    "Son un par de taburetes constituidos por una sección de un tronco sustentada por "
    "cuatro toscas patas cortas encajadas en la pieza principal.\n");
    AddDetail("tarima",
    "Es una plataforma de tablas situada a unos treinta centímetros del suelo y "
    "sostenida mediante dos largas secciones cuadradas de madera  que se sitúan en "
    "los extremos del conjunto.\n");       	    AddExit("sur", "./traspuertao");
    AddDetail("hogar",
    "El hogar se compone de un semicírculo de piedras regulares que encierran contra el "
    "muro de la cabaña el espacio donde se enciende el fuego.\n");
    AddDetail(({"techo","vigas"}),
    "Gruesas vigas de castaño soportan el techo de anchas tablas a dos aguas.\n"
    "Una viga maestra recorre la división entre ambas aguas y sobre ella se sustenta "
    "todo el conjunto.\n");
    AddDetail(({"pared", "paredes"}),
    "Los muros de la caseta de guardia están formados por piedras irregulares poco "
    "talladas unidas con argamasa.\n");
    AddDetail("ganchos",
    "Unos ganchos de bronce incrustados en el muro en los que pueden colgarse todo tipo "
    "de objetos.\n");
    AddDetail("suelo",
    "El suelo está hecho de tierra batida y más o menos apisonada que adquiere una "
    "consistencia pétrea alrededor del hogar, debido al calor que recibe del fuego.\n");
    	    AddDoor("sur", "la puerta",
    	  "Es una robusta puerta de madera formada por anchos tablones.\n"
    	    "Puede cerrarse corriendo un gran pestillo de hierro y en la parte alta se "
    	    "encuentra un pequeño ventanuco por donde se puede vigilar el camino y "
    	    "la puerta de la empalizada sin necesidad de salir al exterior.\n",
    	   ({"puerta", "sur", "s", "caseta"}));
   }