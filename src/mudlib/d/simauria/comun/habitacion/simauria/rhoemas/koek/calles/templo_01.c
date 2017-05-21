/***************************************************************************************
 ARCHIVO:	templo_01.c
 AUTOR:		[z] Zomax
 FECHA:		27-12-2001
 COMENTARIOS:	Calle que lleva al templo
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("roome");

create () {
    ::create();

    SetLocate("Koek");
    SetIntShort("la calle Cendaf");
    carcel=(RHOEHAB("koek/calles/cendaf_00"));

    AddDetail(({"templo","Templo","templo de seri-solderteg","Templo de Seri-Solderteg",
      "seri-solderteg","Seri-Solderteg"}),
  	"Si te acercas un poco más lo verás mejor.\n");
    AddDetail(({"pueblo","koek","Koek"}),"Muy bonito... dan ganas de quedarse para siempre.\n");
    AddExit("norte",RHOEHAB("koek/calles/templo_00"));
    AddExit("sur",RHOEHAB("koek/calles/cendaf_00"));
    AddItem(RHOEPNJ("koek/varios/peregrino"),REFRESH_DESTRUCT,2);
    map[neu,des]= "Estás en una calle a las afueras de Koek que lleva al Templo de "
  	"Seri-Solderteg. Si sigues hacia el norte llegarás a él, y hacia el sur "
  	"regresas al pueblo. ";
}