/***************************************************************************************
 ARCHIVO:	piedra_verde.c
 AUTOR:		[k] Korsario
 FECHA:		10-02-1999
 COMENTARIOS:	Una piedra verde
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create(){
  ::create();
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"_piedra_verde_","piedra","piedra verde"}));
  SetWeight(10);

  SetShort("una piedra verde");
  SetLong("Es una extraña y bonita piedra verde. Es bastante suave "
            "al tacto y opaca, aunque a veces desprende extraños destellos "
  	        "verdes. Nunca habías visto una piedra así. Aparte de eso no "
  	        "parece tener gran valor.\n");
}
