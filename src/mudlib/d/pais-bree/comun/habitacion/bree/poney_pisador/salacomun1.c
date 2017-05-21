/*
Fichero: salacomun1.c
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
    	SetIntLong("La sala com�n del Poney Pisador es la zona en torno a la cual se "
    	"desarrolla la vida de la posada. Tambi�n es el lugar de reuni�n m�s concurrido e "
    	"importante del Pa�s de Bree, donde pueden intercambiarse chismorreos y recogerse "
    	"noticias de lugares lejanos.\n"
    	"Es una larga sala que discurre de norte a sur cuyas ventanas miran al oeste y "
    	"que est� repleta de bancos y mesas ocupadas por una heterog�nea concurrencia.\n"
    	"La enorme chimenea en la que ruge  un llameante ffuego da luz y calor a toda la "
    	"sala y tres faroles cuelgan de las oscuras vigas del techo.\n"
    	"El suelo es de madera y los muros de piedra, y las figuras de los parroquianos se "
    	"desdibujan de forma vaga en la atm�sfera colmada de humo de le�a y tabaco.\n"
    	"Una gran puerta de doble batiente, siempre abierta de par en par y sujeta con "
    	"peque�os tacos de madera da acceso al recibidor situado al este.\n"
    	"Un gran tabl�n se apoya en el fuste de la chimenea y junto  a la puerta cuelga un "
    	"cartel de madera con algo escrito.\n");
    	AddDetail("cartel",
    	"Junto a la puerta cuelga un cartel con una lista de productos que se pueden comprar en la posada.\n");
    	    SetIndoors(1);
    SetIntBright(30);
     AddExit("norte", "./salacomun2");
     AddExit("este", "./recibidor"); 
 }