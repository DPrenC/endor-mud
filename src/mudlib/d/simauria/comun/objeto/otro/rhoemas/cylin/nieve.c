/***************************************************************************************
 ARCHIVO:	nieve.c
 AUTOR:		[z] Zomax
 FECHA:		28-11-2001
 COMENTARIOS:	Nieve del bosque Cylin
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

int fderretir()
{
	tell_object(environment(TO),W("La nieve se ha derretido por "
		 "completo del calor.\n"));
 	TO->remove();
 	return 1;
}

create () {
 ::create();

 SetShort("un poco de nieve");
 SetLong(W("Es nieve, agua muy muy fría o como quieras llamarle. Es "
 	    "completamente blanca y está hecha a base de pequeños "
 	    "cristalitos de hielo.\n"));
 AddSubDetail(({"cristales","cristalitos"}),"Casi no los ves, son enanísimos.\n");
 SetIds(({"nieve"}));
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(100);
 SetValue(0);
 call_out("fderretir",100);
}
