/***************************************************************************************

 ARCHIVO:	parque.c

 AUTOR:		[z] Zomax

 FECHA:		15-12-2001

 COMENTARIOS:	Parque de Koek

 ***************************************************************************************/



#include "path.h"



inherit RHOESTD("roome");



create () {

    ::create();



    SetLocate("Koek");

    SetIntShort("un parque"); 

    AddDetail(({"banco","bancos"}),"Hay unos bonitos bancos de piedra en el parque "
  	"para sentarse.\n");

    carcel=(RHOEHAB("koek/calles/cendaf_02"));


    AddExit("oeste",RHOEHAB("koek/calles/cendaf_02"));

    AddItem(RHOEPNJ("koek/varios/thobwyn"),REFRESH_DESTRUCT);
    AddItem(RHOEPNJ("koek/ciudadanos/anciano"),REFRESH_DESTRUCT);
    AddItem(RHOEPNJ("koek/ciudadanos/anciana"),REFRESH_DESTRUCT);
    AddItem(RHOEPNJ("koek/varios/gato"),REFRESH_DESTRUCT, d2());

    map[neu,des]= "Estás en un pequeño pero muy cuidado parque. Hay varios "

  		"bancos para sentarse que los viejos del lugar y los niños "

  		"aprovechan cuando hay buen tiempo para charlar, sobre todo "

  		"en primavera y verano. Es un sitio muy tranquilo. ";

}



int QueryEntrarPatrullero()

{

	return 1;

}



int QueryEntrarGato()

{

	return 1;

}
