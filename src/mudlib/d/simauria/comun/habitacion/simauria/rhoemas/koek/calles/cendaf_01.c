/***************************************************************************************
 ARCHIVO:	cendaf_01.c
 AUTOR:		[z] Zomax
 FECHA:		14-11-2001
 COMENTARIOS:	Calle Cendaf de Koek
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("roome");

create () {
    ::create();

    SetLocate("Koek");
    SetIntShort("la calle Cendaf");
    carcel=(RHOEHAB("koek/calles/cendaf_02"));

    AddExit("norte",RHOEHAB("koek/calles/cendaf_00"));
    AddExit("sur",RHOEHAB("koek/calles/cendaf_02"));
    AddExit("este",RHOEHAB("koek/tiendas/carpinteria"));
    AddExit("oeste",RHOEHAB("koek/tiendas/herreria"));
    AddItem(RHOEPNJ("koek/varios/patrullero"),REFRESH_DESTRUCT);
    AddItem(RHOEPNJ("koek/varios/peregrino"),REFRESH_DESTRUCT,2);
    map[neu,des]= "Estás en la calle Cendaf. Es una calle algo transitada que "
		"congrega a varios comercios. Al norte la calle sigue hacia "
		"el templo de Seri-Solderteg. Al sur la calle lleva a la "
		"plaza Zendak, dedicada al fundador de Koek. Al oeste puedes "
		"ver la tienda del herrero del pueblo y al este la carpintería "
		"local. ";
}