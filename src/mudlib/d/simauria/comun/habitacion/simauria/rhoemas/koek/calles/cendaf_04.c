/***************************************************************************************
 ARCHIVO:	cendaf_04.c
 AUTOR:		[z] Zomax
 FECHA:		26-12-2001
 COMENTARIOS:	Calle Cendaf de Koek
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("roome");

create () {
    ::create();

    SetLocate("Koek");
    SetIntShort("la calle Cendaf");
    carcel=(RHOEHAB("koek/calles/folker_07"));

    AddExit("norte",RHOEHAB("koek/calles/plaza"));
    AddExit("sur",RHOEHAB("koek/calles/cendaf_05"));
    AddExit("nordeste",RHOEHAB("koek/calles/folker_07"));
    AddExit("noroeste",RHOEHAB("koek/calles/folker_06"));

    map[neu,des]= "Te encuentras en el interior de Koek. Esta calle, que "
  	"se extiende desde el norte donde se alza el templo de "
  	"Seri-Solderteg, hasta la salida al sur, es denominada "
  	"Cendaf por sus habitantes y es junto a Folker una de las "
  	"principales vías del pueblo. ";
}