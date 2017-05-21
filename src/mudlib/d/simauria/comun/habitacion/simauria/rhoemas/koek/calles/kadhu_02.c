/***************************************************************************************
 ARCHIVO:	kadhu_02.c
 AUTOR:		[z] Zomax
 FECHA:		14-11-2001
 COMENTARIOS:	Calle Kadhu de Koek
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("roome");

create () {
    ::create();

    SetLocate("Koek");
    SetIntShort("la calle Kadhu");
    carcel=(RHOEHAB("koek/calles/kadhu_03"));

    AddExit("norte",RHOEHAB("koek/calles/kadhu_01"));
    AddExit("sur",RHOEHAB("koek/calles/kadhu_03"));
    AddExit("este",RHOEHAB("koek/tiendas/verduleria"));
    AddExit("oeste",RHOEHAB("koek/tiendas/fruteria"));

    map[neu,des]="Estás en la calle Kadhu, en Koek. Puedes ver que la calle sigue hacia "+
 	      "el norte y el sur, recorriendo varios comercios. Al este hay una verduleria "+
 	      "y al oeste una fruteria. Si sigues hacia el norte verás el cruce con la "+
 	      "calle Folker. ";
}