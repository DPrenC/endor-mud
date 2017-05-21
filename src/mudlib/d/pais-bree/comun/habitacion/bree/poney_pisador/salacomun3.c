/*
Fichero: salacomun3.c
Autor: aulë
Fecha: 15/03/2013
Descripción:  un rincón de la sala común del Poney Pisador. 
*/
#include "./path.h"
inherit HABITACION+"bree/poney_pisador/bsalacomun";
create()
{
    ::create();
    	SetIntShort("un discreto rincón de la sala común");
    	SetIntLong("A esta zona de la larga sala común de la posada llega menos luz de el "
    	"rugiente fuego situado en el lado opuesto de la sala, lo que lo hace ser un "
    	"rincón algo más oscuro y discreto, ideal para los conciliábulos privados y para "
    	"que quien quiera pasar desapercibido pueda hacerlo mientras observa el resto de "
    	"la estancia.\n"
    	"Bancos y mesas ocupan el lugar, apoyándose alguno contra el grueso muro de piedra.\n"
    	"Uno de los tres faroles de la sala cuelga de las vigas del ennegrecido techo, "
    	"pero su débil luz no llega a iluminar gran cosa.\n"
    	"Espesas cortinas cuelgan ante las ventanas y el humo de leña y tabaco está llena "
    	"de las voces, canciones y risas de la variada concurrencia que se acomoda en los "
    	"bancos y mesas.\n");
    	    SetIndoors(1);
    SetIntBright(20);
     AddExit("sur", "./salacomun2"); 
    }