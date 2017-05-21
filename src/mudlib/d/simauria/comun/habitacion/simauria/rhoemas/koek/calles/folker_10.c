/***************************************************************************************
 ARCHIVO:	folker_10.c
 AUTOR:		[z] Zomax
 FECHA:		08-11-2001
 COMENTARIOS:	Calle Folker de Koek
 MODIFICACION:  07-04-03 Quito un par de variables que no tengo ni idea de por qué dejé.
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("roome");

create () {
    ::create();

    SetLocate("Koek");
    SetIntShort("la calle Folker");
    carcel=(RHOEHAB("koek/carcel/entrada"));

    AddExit("norte",RHOEHAB("koek/varios/taquillas"));
    AddExit("este",RHOEHAB("koek/carcel/entrada"));
    AddExit("oeste",RHOEHAB("koek/calles/folker_09"));

    map[neu,des]= "Aquí termina la calle de Folker, que empieza muy al "
  		"oeste en el molino. Al este puedes ver la entrada a "
  		"la cárcel, custodiada por la guardia de la ciudad. "
  		"Al norte está la oficina de consignas, mientras Al oeste la calle "
  		"discurre hasta cruzarse con la entrada a la posada. ";
}