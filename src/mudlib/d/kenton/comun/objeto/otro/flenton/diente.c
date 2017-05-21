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
  SetLong("Es un diente aserrado. Tiene forma c�nica y mide unos 5 "
  	"cent�metros de largo.\n");
  SetExtra("Hmm..., al fijarte mejor te da la impresi�n de que se "
  	"trata de un diente de tibur�n.\n");
}
