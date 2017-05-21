/***************************************************************************************
 ARCHIVO:	cendaf_00.c
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
    carcel=(RHOEHAB("koek/calles/cendaf_01"));

    AddExit("norte",RHOEHAB("koek/calles/templo_01"));
    AddExit("sur",RHOEHAB("koek/calles/cendaf_01"));
    AddExit("este",RHOEHAB("koek/tiendas/pitonisa"));
    AddExit("oeste",RHOEHAB("koek/tiendas/herbolario"));
    AddItem(RHOEPNJ("koek/ciudadanos/ciudadana2"),REFRESH_DESTRUCT);
    map[neu,des]= "Te encuentras en la calle Cendaf, la calle que reune a "
  		"los artesanos de Koek y a algunos tenderos. Al norte está "
  		"el camino que lleva al templo de Seri-Solderteg y al sur "
  		"la calle discurre con normalidad. Al oeste puedes ver la "
  		"tienda de un herbolario y al este la consulta de la "
  		"pitonisa local. ";
}