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
 SetLong(W("Es un nido, el peque�o hogar de un pajarillo que alg�n "
 	    "v�ndalo ha cojido sin permiso. Est� perfectamente hecho "
 	    "a base de ramitas y hojas y parece muy s�lido.\n"));
 AddSubDetail(({"ramitas","hojas"}),W("Son ramas y hojas muy peque�as. Alg�n p�jaro "
 	"se tom� su tiempo en confeccionarlo.\n"));
 SetIds(({"nido"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(500);
 SetValue(0);
}