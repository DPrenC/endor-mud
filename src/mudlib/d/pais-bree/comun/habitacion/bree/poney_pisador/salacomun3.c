/*
Fichero: salacomun3.c
Autor: aul�
Fecha: 15/03/2013
Descripci�n:  un rinc�n de la sala com�n del Poney Pisador. 
*/
#include "./path.h"
inherit HABITACION+"bree/poney_pisador/bsalacomun";
create()
{
    ::create();
    	SetIntShort("un discreto rinc�n de la sala com�n");
    	SetIntLong("A esta zona de la larga sala com�n de la posada llega menos luz de el "
    	"rugiente fuego situado en el lado opuesto de la sala, lo que lo hace ser un "
    	"rinc�n algo m�s oscuro y discreto, ideal para los concili�bulos privados y para "
    	"que quien quiera pasar desapercibido pueda hacerlo mientras observa el resto de "
    	"la estancia.\n"
    	"Bancos y mesas ocupan el lugar, apoy�ndose alguno contra el grueso muro de piedra.\n"
    	"Uno de los tres faroles de la sala cuelga de las vigas del ennegrecido techo, "
    	"pero su d�bil luz no llega a iluminar gran cosa.\n"
    	"Espesas cortinas cuelgan ante las ventanas y el humo de le�a y tabaco est� llena "
    	"de las voces, canciones y risas de la variada concurrencia que se acomoda en los "
    	"bancos y mesas.\n");
    	    SetIndoors(1);
    SetIntBright(20);
     AddExit("sur", "./salacomun2"); 
    }