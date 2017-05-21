/*
Fichero: salacomun2.c
Autor: aulë
Fecha: 15/03/2013
Descripción:  la sala común del Poney Pisador. 
*/
#include "./path.h"
inherit HABITACION+"bree/poney_pisador/bsalacomun";

create()
{
    ::create();
    	SetIntShort("salón común del Poney Pisador");
    	SetIntLong("La sala común de la posada es una larga sala repleta de mesas y bancos,"
    	" con ventanas que miran al oeste, cubiertas por espesas cortinas.\n"
    	"Una variopinta concurrencia ocupa los bancos y las voces, canciones y risas "
    	"invaden la calurosa atmósfera algo viciada por el humo de leña y tabaco, que "
    	"oculta el techo del que cuelgan tres faroles, y los muros de piedra en las que "
    	"las sombras producidas por la luz del llameante fuego que arde en la chimenea "
    	"situada al sur.\n");
    	    SetIndoors(1);
    SetIntBright(25);
     AddExit("sur", "./salacomun1");
     AddExit("norte", "./salacomun3"); 
    }