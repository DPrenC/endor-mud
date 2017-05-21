/*
Fichero: salacomun2.c
Autor: aul�
Fecha: 15/03/2013
Descripci�n:  la sala com�n del Poney Pisador. 
*/
#include "./path.h"
inherit HABITACION+"bree/poney_pisador/bsalacomun";

create()
{
    ::create();
    	SetIntShort("sal�n com�n del Poney Pisador");
    	SetIntLong("La sala com�n de la posada es una larga sala repleta de mesas y bancos,"
    	" con ventanas que miran al oeste, cubiertas por espesas cortinas.\n"
    	"Una variopinta concurrencia ocupa los bancos y las voces, canciones y risas "
    	"invaden la calurosa atm�sfera algo viciada por el humo de le�a y tabaco, que "
    	"oculta el techo del que cuelgan tres faroles, y los muros de piedra en las que "
    	"las sombras producidas por la luz del llameante fuego que arde en la chimenea "
    	"situada al sur.\n");
    	    SetIndoors(1);
    SetIntBright(25);
     AddExit("sur", "./salacomun1");
     AddExit("norte", "./salacomun3"); 
    }