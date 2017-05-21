/***************************************************************************************
 ARCHIVO:	kadhu_01.c
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
    carcel=(RHOEHAB("koek/calles/kadhu_02"));

    AddExit("norte",RHOEHAB("koek/calles/kadhu_00"));
    AddExit("sur",RHOEHAB("koek/calles/kadhu_02"));
    AddExit("este",RHOEHAB("koek/tiendas/pescaderia"));
    AddExit("oeste",RHOEHAB("koek/tiendas/carniceria"));
    AddItem(RHOEPNJ("koek/varios/patrullero"),REFRESH_DESTRUCT);
    AddItem(RHOEPNJ("koek/varios/gato"),REFRESH_DESTRUCT);
    map[neu,des]="Esta es la calle Kadhu. Es una típica calle de comerciantes donde "+
 	      "se puede encontrar casi de todo. Al norte la calle termina al lado "+
 	      "de un par de locales abandonados, al sur sigue hacia el cruce con la "+
 	      "calle Folker. Al este puedes ver una pescaderia, y al oeste la carniceria. ";
}