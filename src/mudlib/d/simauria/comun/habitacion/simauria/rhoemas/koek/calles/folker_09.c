/***************************************************************************************
 ARCHIVO:	folker_09.c
 AUTOR:		[z] Zomax
 FECHA:		08-11-2001
 COMENTARIOS:	Calle Folker de Koek
 MODIFICACION:  07-04-03 Quito un par de variables que no tengo ni idea de por qué dejé.
 ***************************************************************************************/

#include "./path.h"

inherit RHOESTD("roome");

create () {
    ::create();

    SetLocate("Koek");
    SetIntShort("la calle Folker");
    carcel=(RHOEHAB("koek/calles/folker_10"));

    AddExit("norte",RHOEHAB("koek/posada/entrada"));
    AddExit("este",RHOEHAB("koek/calles/folker_10"));
    AddExit("oeste",RHOEHAB("koek/calles/folker_08"));
    AddItem(RHOEPNJ("koek/varios/patrullero"),REFRESH_DESTRUCT,2);
    AddItem(RHOEPNJ("koek/varios/peregrino"),REFRESH_DESTRUCT,d3());
    map[neu,des]= "Esta es la calle Folker, una de las vías principales "
  		"de Koek. Se extiende de oeste a  este del pueblo, "
  		"pasando por la plaza. Al norte de aquí ves la posada "
  		"de Koek, también llamada 'La posada de Seri', al este "
  		"ves que la calle sigue hasta la cárcel y correos y al "
  		"oeste la calle se dirige al banco y la plaza de Zendak. ";
}