/***************************************************************************************
 ARCHIVO:	cesped.c
 AUTOR:		[z] Zomax
 FECHA:		28-11-2001
 COMENTARIOS:	Un poco de c�sped del bosque Cylin
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

 SetShort("un poco de c�sped");
 SetLong(W("Es un poco de c�sped del bosque de Cylin, se nota por su tono "
 	    "verdoso tirando a negro, algo poco com�n.\n"));
 SetIds(({"c�sped","cesped"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(250);
 SetValue(0);
}