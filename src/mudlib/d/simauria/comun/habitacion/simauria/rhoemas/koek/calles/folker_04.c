/***************************************************************************************
 ARCHIVO:	folker_04.c
 AUTOR:		[z] Zomax
 FECHA:		08-11-2001
 COMENTARIOS:	Calle Folker de Koek
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("roome");

create () {
    ::create();

    SetLocate("Koek");
    SetIntShort("la calle Folker");
    carcel=(RHOEHAB("koek/calles/folker_05"));

    AddExit("norte",RHOEHAB("koek/calles/kadhu_03"));
    AddExit("sur",RHOEHAB("koek/muelle/muelle_centro"));
    AddExit("este",RHOEHAB("koek/calles/folker_05"));
    AddExit("oeste",RHOEHAB("koek/calles/folker_03"));
    AddItem(RHOEPNJ("koek/varios/patrullero"),REFRESH_DESTRUCT);
     AddItem(RHOEPNJ("koek/ciudadanos/ciudadano"), REFRESH_DESTRUCT);
    map[neu,des]="Te encuentras en la calle Folker. Al norte de aquí está "+
 	    "la calle Kadhu, donde se acumulan una gran cantidad de "+
 	    "tiendas de los comerciantes de Koek. Al sur está el muelle "+
 	    "que se adentra en el lago que forma el río Hedrikon. Al este "+
 	    "y al oeste la calle sigue su camino. ";
}