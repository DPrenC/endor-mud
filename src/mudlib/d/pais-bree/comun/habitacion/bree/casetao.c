/*
Fichero: casetao.c
Autor: aul�
Fecha: 12/03/2013
Descripci�n: caseta de guardia para los vigilantes de la puerta oeste. 
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
    SetIntLong("El interior de la caseta de guardia consta de una peque�a estancia "
    "con muros de piedra sin desvastar, suelo de tierra batida y techo a dos aguas "
    "sustentado por vigas de madera.\n"
    "En una de las paredes se sit�a un hogar de piedra y una serie de ganchos se "
    "alinean en la pared opuesta.\n"
    "Frente a la puerta y apoyada contra la pared hay una tarima de madera para que el "
    "vigilante descanse cuando as� se lo permitan sus obligaciones.\n"
    "Junto al hogar hay un par de toscos taburetes.\n");
    AddDetail(({"taburete", "taburetes"}),
    "Son un par de taburetes constituidos por una secci�n de un tronco sustentada por "
    "cuatro toscas patas cortas encajadas en la pieza principal.\n");
    AddDetail("tarima",
    "Es una plataforma de tablas situada a unos treinta cent�metros del suelo y "
    "sostenida mediante dos largas secciones cuadradas de madera  que se sit�an en "
    "los extremos del conjunto.\n");       	    AddExit("sur", "./traspuertao");
    AddDetail("hogar",
    "El hogar se compone de un semic�rculo de piedras regulares que encierran contra el "
    "muro de la caba�a el espacio donde se enciende el fuego.\n");
    AddDetail(({"techo","vigas"}),
    "Gruesas vigas de casta�o soportan el techo de anchas tablas a dos aguas.\n"
    "Una viga maestra recorre la divisi�n entre ambas aguas y sobre ella se sustenta "
    "todo el conjunto.\n");
    AddDetail(({"pared", "paredes"}),
    "Los muros de la caseta de guardia est�n formados por piedras irregulares poco "
    "talladas unidas con argamasa.\n");
    AddDetail("ganchos",
    "Unos ganchos de bronce incrustados en el muro en los que pueden colgarse todo tipo "
    "de objetos.\n");
    AddDetail("suelo",
    "El suelo est� hecho de tierra batida y m�s o menos apisonada que adquiere una "
    "consistencia p�trea alrededor del hogar, debido al calor que recibe del fuego.\n");
    	    AddDoor("sur", "la puerta",
    	  "Es una robusta puerta de madera formada por anchos tablones.\n"
    	    "Puede cerrarse corriendo un gran pestillo de hierro y en la parte alta se "
    	    "encuentra un peque�o ventanuco por donde se puede vigilar el camino y "
    	    "la puerta de la empalizada sin necesidad de salir al exterior.\n",
    	   ({"puerta", "sur", "s", "caseta"}));
   }