/***************************************************************************************
 ARCHIVO:	escombros.c
 AUTOR:		[z] Zomax
 FECHA:		20-11-2001
 COMENTARIOS:	Escombros (cadaver) de cualquier estatua
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

 SetShort("unos escombros");
 SetLong(W("Son los restos de algún tipo de construcción o escultura que "
 	    "alguien ha reducido a escombros.\n"));
 SetIds(({"escombros","restos"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_PLURAL);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(20000);
 SetValue(0);
}
