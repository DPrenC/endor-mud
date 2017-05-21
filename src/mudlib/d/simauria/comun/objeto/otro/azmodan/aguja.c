/***********************************************************/
//	"aguja"
//	Una aguja para rituales de vud�
//	27-11-01 : Creaci�n -> Kodex
//	27-11-01 : Modificaci�n -> Kodex
//
//

inherit THING;
#include <properties.h>
#include "./path.h"
create()
{
::create();
SetShort("una aguja de vud�");
SetLong(W("Es una aguja peque�a utilizada por algunas culturas"
" en ritos de magia negra con mu�ecos, est� muy afilada.\n"));
SetIds(({"aguja"}));
SetWeight(100);
Set(P_GENDER,GENERO_FEMENINO);
Set(P_NUMBER,NUMERO_SINGULAR);
Set(P_NOSELL);
}