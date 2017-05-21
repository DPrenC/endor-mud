/***************************************************************************************
 ARCHIVO:	cendaf_03.c
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
    carcel=(RHOEHAB("koek/calles/folker_07"));

    AddExit("norte",RHOEHAB("koek/calles/cendaf_02"));
    AddExit("sur",RHOEHAB("koek/calles/plaza"));
    AddExit("este",RHOEHAB("koek/varios/alcaldia"));
    AddExit("oeste",RHOEHAB("koek/varios/biblioteca"));
    AddExit("sudeste",RHOEHAB("koek/calles/folker_07"));
    AddExit("suroeste",RHOEHAB("koek/calles/folker_06"));
    AddItem(RHOEPNJ("koek/ciudadanos/jovencita"), REFRESH_DESTRUCT);
    map[neu,des]= "Estás en la calle Cendaf. Es una típica calle de pueblo "
  		"bastante transitada. Al norte la calle sigue hacia el "
  		"templo, y al sur está la plaza Zendak, dedicada al "
  		"fundador de Koek. Al sudeste y suroeste enlazas con la "
  		"calle Folker. Al oeste está la biblioteca de Koek y justo "
  		"enfrente, al este, el ayuntamiento. ";
}