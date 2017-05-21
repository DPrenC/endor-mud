/***************************************************************************************
 ARCHIVO:	cendaf_05.c
 AUTOR:		[z] Zomax
 FECHA:		26-12-2001
 COMENTARIOS:	Calle Cendaf de Koek
 MODIFICACION:  27-04-2003 A�ado salida a la casa del alquimista.
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("roome");

create () {
    ::create();

    SetLocate("Koek");
    SetIntShort("la calle Cendaf");
    carcel=(RHOEHAB("koek/calles/cendaf_04"));

    AddExit("norte",RHOEHAB("koek/calles/cendaf_04"));
    AddExit("sur",RHOEHAB("koek/calles/cendaf_06"));
    AddExit("oeste",RHOEHAB("koek/varios/alquimia"));
    AddItem(RHOEPNJ("koek/varios/peregrino"),REFRESH_DESTRUCT,2);
    map[neu,des]= "Desde aqu� puedes observar la plaza de Zendak hacia "
  	"el norte, donde se extiende el pueblo de Koek y el famoso "
  	"templo de Seri-Solderteg. El camino tambi�n se extiende hacia "
  	"el sur, alej�ndose del pueblo. ";
  	
    AddDetail(({"plaza","plaza de Zendak","plaza de zendak"}),W("Puedes "
  	"ver la plaza de Zendak, pero si te acercas un poco m�s podr�s "
  	"verla con todo detalle.\n"));
}