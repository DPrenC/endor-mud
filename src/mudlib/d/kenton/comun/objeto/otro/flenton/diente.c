/***************************************************************************************
 ARCHIVO:	diente.c
 AUTOR:		[o] Okkita
 FECHA:		10-02-1999
 COMENTARIOS:	Un diente
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create(){
  ::create();
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"diente"}));
  SetValue(50);
  SetWeight(2);

  SetShort("un diente");
  SetLong("Es un diente aserrado. Tiene forma cónica y mide unos 5 "
  	"centímetros de largo.\n");
  SetExtra("Hmm..., al fijarte mejor te da la impresión de que se "
  	"trata de un diente de tiburón.\n");
}
