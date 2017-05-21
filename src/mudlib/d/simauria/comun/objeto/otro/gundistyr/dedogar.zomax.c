/* ******************************************************
   *                                                    *
   *  Archivo:      dedogar.c                           *
   *  Autor:        [a] Articman                        *
   *  Descripci�n:  Objeto para dar y completar quest.  *
   *                Se consigue matando a la g�rgola.   *
   *  Modificaci�n: 31/01/02 [a] Creaci�n               *
   ******************************************************  */


inherit THING;
#include <properties.h>
#include "path.h"

create() {
::create();
SetShort("un dedo de g�rgola");
SetLong(W("Es un largo dedo de g�rgola viva. Mide unos "
"20 cm de largo. Es de color oscuro y restos de sangre "
"roja. Acaba en una afilada y negra u�a.\n"));
SetIds(({"dedo gargola","dedo g�rgola","dedo de gargola"
,"dedo de g�rgola","dedo","d_gargola"}));
Set(P_GENDER,GENERO_MASCULINO);
Set(P_NUMBER,NUMERO_SINGULAR);
SetWeight(100);
Set(P_CANT_STEAL,1);
  Set(P_NOGIVE, 1);
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
  Set(P_NOBUY, 1);
}
