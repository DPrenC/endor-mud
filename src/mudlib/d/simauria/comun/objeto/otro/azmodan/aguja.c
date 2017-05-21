/***********************************************************/
//	"aguja"
//	Una aguja para rituales de vudú
//	27-11-01 : Creación -> Kodex
//	27-11-01 : Modificación -> Kodex
//
//

inherit THING;
#include <properties.h>
#include "./path.h"
create()
{
::create();
SetShort("una aguja de vudú");
SetLong(W("Es una aguja pequeña utilizada por algunas culturas"
" en ritos de magia negra con muñecos, está muy afilada.\n"));
SetIds(({"aguja"}));
SetWeight(100);
Set(P_GENDER,GENERO_FEMENINO);
Set(P_NUMBER,NUMERO_SINGULAR);
Set(P_NOSELL);
}