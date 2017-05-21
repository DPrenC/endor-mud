/***************************************************************************************
 ARCHIVO:	caravanas.c
 AUTOR:		[z] Zomax
 FECHA:		14-12-2001
 COMENTARIOS:	Parada de las caravanas
 MODIFICACION:  18-04-2003 Añado al basurero.
 ***************************************************************************************/

#include "./path.h"

inherit STAGECOACH_STOP;
#include RHOEPRESO

create () {
    ::create();

    SetLocate("Koek");
    SetIntShort("la parada de la diligencia");
    SetNombreParada("Koek");
    AddDiligencia(RHOEK("rhoek"));
    SetIntLong("Estás en la parada de la diligencia que llega a Koek y que comunica "
  		" el valle de Rhoemas con el resto del mundo. Parece que el transporte "
  		"aquí es algo muy importante y han acondicionado este lugar para que "
  		"ofrezca el mejor servicio.\n Puedes leer un cartel que hay colgado de un poste.\n");
    carcel=RHOEHAB("koek/calles/cendaf_02");

    SetClimateServer(SERVER);
    AddExit("este",RHOEHAB("koek/calles/cendaf_02"));
    AddItem(RHOEPNJ("koek/varios/barin"),REFRESH_DESTRUCT);
    AddItem(RHOEPNJ("koek/ciudadanos/ciudadano2"),REFRESH_DESTRUCT);
    SetKeeper(PNJ("diligencia/taquillero"));
}