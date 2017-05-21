/***************************************************************************************
 ARCHIVO:	eslabon.c
 AUTOR:		[o] Okkita
 FECHA:		10-02-1999
 COMENTARIOS:	Un eslab�n
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create(){
  ::create();
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"eslabon","eslab�n"}));
  SetValue(10);
  SetWeight(50);

  SetShort("un eslab�n");
  SetLong("Es un eslab�n de una cadena. Le falta el resto de la cadena, "
  	"pero es un buen comienzo.\n");
  SetExtra("Hmm..., este eslab�n no tiene marcas de desgaste... no parece "
  	"haber sido nunca parte de una cadena.\n");
}
