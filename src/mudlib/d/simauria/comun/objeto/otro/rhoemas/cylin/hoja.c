/***************************************************************************************
 ARCHIVO:	hoja.c
 AUTOR:		[z] Zomax
 FECHA:		28-11-2001
 COMENTARIOS:	Hoja del bosque Cylin
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

 SetShort("una hoja marchita");
 SetLong(W("Es una hoja ca�da de alg�n �rbol. Est� algo marchita, y marr�n "
 	    "y no parece que sirva de mucho.\n"));
 SetIds(({"hoja"}));
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(100);
 SetValue(0);
}
