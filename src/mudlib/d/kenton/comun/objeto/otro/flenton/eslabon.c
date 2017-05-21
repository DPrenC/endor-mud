/***************************************************************************************
 ARCHIVO:	eslabon.c
 AUTOR:		[o] Okkita
 FECHA:		10-02-1999
 COMENTARIOS:	Un eslabón
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create(){
  ::create();
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"eslabon","eslabón"}));
  SetValue(10);
  SetWeight(50);

  SetShort("un eslabón");
  SetLong("Es un eslabón de una cadena. Le falta el resto de la cadena, "
  	"pero es un buen comienzo.\n");
  SetExtra("Hmm..., este eslabón no tiene marcas de desgaste... no parece "
  	"haber sido nunca parte de una cadena.\n");
}
