/***************************************************************************************
 ARCHIVO:	kadhu_00.c
 AUTOR:		[z] Zomax
 FECHA:		148-11-2001
 COMENTARIOS:	Calle Kadhu de Koek.
 MODIFICACION:  22-04-2003 Cambio un poco la descripción y al este ahora la salida en
 			   lugar de un local abandonado está el taller del sastre.
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("roome");

create () {
    ::create();

    SetLocate("Koek");
    SetIntShort("la calle Kadhu");
    carcel=(RHOEHAB("koek/calles/kadhu_01"));

    AddExit("sur",RHOEHAB("koek/calles/kadhu_01"));
    AddExit("este",RHOEHAB("koek/tiendas/sastreria"));
    AddExit("oeste",RHOEHAB("koek/tiendas/abandonado_oeste"));
    AddItem(RHOEPNJ("koek/ciudadanos/joven_ciudadana"), REFRESH_DESTRUCT);
   map[neu,des]="Estás en la calle Kadhu, en Koek. Es una calle repleta de comercios "+
 	      "muy transitada. Hacia el sur la calle sigue su camino y al oeste ves "
 	      "un local abandonado. Al este puedes ver el taller del sastre local. ";
}