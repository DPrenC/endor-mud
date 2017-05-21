/***************************************************************************************
 ARCHIVO:	kadhu_03.c
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
    carcel=(RHOEHAB("koek/calles/folker_04"));

    AddExit("norte",RHOEHAB("koek/calles/kadhu_02"));
    AddExit("sur",RHOEHAB("koek/calles/folker_04"));
    AddExit("este",RHOEHAB("koek/tiendas/lecheria"));
    AddExit("oeste",RHOEHAB("koek/tiendas/panaderia"));
    AddItem(RHOEPNJ("koek/ciudadanos/joven_ciudadano"), REFRESH_DESTRUCT);
   map[neu,des]="Te encuentras en la calle Kadhu. Desde aquí ves al oeste una panaderia, y "+
 	      "al este una lecheria. Al norte la calle se adentra en los comercios, y al sur "+
 	      "está el cruce con la calle Folker, que va desde el molino hasta la cárcel, "+
 	      "pasando por la plaza Zendak. ";
}