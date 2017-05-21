/***************************************************************************************
 ARCHIVO:	nido.c
 AUTOR:		[z] Zomax
 FECHA:		28-11-2001
 COMENTARIOS:	Un nido del bosque Cylin
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

 SetShort("un nido");
 SetLong(W("Es un nido, el pequeño hogar de un pajarillo que algún "
 	    "vándalo ha cojido sin permiso. Está perfectamente hecho "
 	    "a base de ramitas y hojas y parece muy sólido.\n"));
 AddSubDetail(({"ramitas","hojas"}),W("Son ramas y hojas muy pequeñas. Algún pájaro "
 	"se tomó su tiempo en confeccionarlo.\n"));
 SetIds(({"nido"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(500);
 SetValue(0);
}