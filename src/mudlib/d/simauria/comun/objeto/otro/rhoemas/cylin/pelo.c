/***************************************************************************************
 ARCHIVO:	pelo.c
 AUTOR:		[z] Zomax
 FECHA:		28-11-2001
 COMENTARIOS:	Un poco de pelo de algún animal del bosque Cylin
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

 SetShort("un poco de pelo");
 SetLong(W("Parece algo de pelo de algún animal del bosque... Es marrón y "
 	    "algo brillante, podría ser de un oso al rascarse con los árboles.\n"));
 SetIds(({"pelo"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(50);
 SetValue(0);
}