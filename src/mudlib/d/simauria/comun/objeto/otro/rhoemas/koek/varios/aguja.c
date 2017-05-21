/***************************************************************************************
 ARCHIVO:	aguja.c
 AUTOR:		[z] Zomax
 FECHA:		24-04-2003
 COMENTARIOS:	Una aguja especial de platino.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

 SetShort("una aguja de platino");
 SetLong("Es una elaborada aguja de platino muy resistente pero a la vez delicada.\n");
 SetIds(({"aguja","aguja de platino"}));
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_SMALL);
 SetWeight(2);
 SetValue(0);
}
