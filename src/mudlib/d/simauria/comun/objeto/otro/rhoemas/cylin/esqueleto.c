/***************************************************************************************
 ARCHIVO:	esqueleto.c
 AUTOR:		[z] Zomax
 FECHA:		28-11-2001
 COMENTARIOS:	Un esqueleto de algún animal del bosque Cylin
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

 SetShort("un esqueleto");
 SetLong("Parece el esqueleto de un animal, un lobo o un zorro o algún animal de ese tipo.\n");
 SetIds(({"esqueleto"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(15000);
 SetValue(0);
}