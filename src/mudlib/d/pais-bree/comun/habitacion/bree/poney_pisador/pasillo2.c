/*
Fichero: pasillo2.c
Autor: aul�
Fecha: 31/03/2013
Descripci�n:  pasillos de la posada. 
*/
#include "./path.h"
inherit HABITACION+"bree/poney_pisador/bpasillo";
create()
{
    ::create();
    	SetIntShort("un pasillo");
    	SetIntLong("El pasillo transcurre de este a oeste a lo largo de la planta baja de "
    	"la posada, iluminado por faroles de aceite que cuelgan del techo.\n"
    	"Suelo y muros est�n confeccionados en piedra, dando testimonio de la solidez y "
    	"antig�edad de la posada del Poney Pisador.\n"
    	"Al norte ves una puerta redonda que da acceso a uno de los cuartos para hobbits y "
    	"al este se levanta una escalera que da paso a las plantas superiores de la posada.\n");
    	   AddDetail("suelo",
   "El suelo est� hecho de losas de piedra muy antigua y pulida por el paso de "
   "innumerables pies.\n");
   AddDetail(({"muros", "paredes"}),
   "Los gruesos muros est�n levantados con pesados bloques de piedra de forma "
   "irregular y superficie toscamente alisada.\n");
   AddDetail(({"este", "pasillo"}),
   "Al este se extiende el pasillo al final del cual vislumbras una escalera que "
   "asciende al piso superior.\n");
    	    SetIndoors(1);
    SetIntBright(20);
     AddExit("oeste", "./pasillo1");
     AddExit("norte", "./cuartohobbit1");
     AddExit("este", "./pasillo3");
     AddDoor("norte", "una puerta redonda",
     "Es una peque�a puerta redonda del estilo que gusta a los hobbits.\n"
     "Est� hecha de madera que, aunque aparenta antigua, est� bien pulida y barnizada.\n"
     "En el centro tiene una manilla de bronce de pomo redondeado para abrir y cerrar la puerta.\n",
     ({"norte", "n", "puerta norte", "puerta hobbit", "redonda", "puerta redonda"})); 
    }