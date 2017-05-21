/***************************************************************************************
 ARCHIVO:	tapiz.c
 AUTOR:		[k] Korsario
 FECHA:		10-02-1999
 COMENTARIOS:	Un tapiz
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create(){
  ::create();
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"emblema","tapiz"}));
  SetValue(20);
  SetWeight(100);

  SetShort("un tapiz");
  SetLong("Es un tapiz muy bonito que representa a un gran árbol. En el "
  	"troco del árbol hay incrustada una piedra verde que parece brillar. "
  	"Es el emblema de Flenton\n");
}
