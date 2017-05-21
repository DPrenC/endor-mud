/***********************************************************/
//	"piedra"
//	piedra preciosa
//	11-12-01 : Creación -> Kodex
//	11-12-01 : Modificación -> Kodex
//
//
inherit THING;
#include <properties.h>
#include "./path.h"
create()
{
::create();
SetShort("una brillante piedra preciosa");
SetLong(W("Es un cristal de un color azulado y verdoso, por su peso"
" crees que debe estar bien valorado. Cuando la luz atraviesa la piedra "
"se ilumina con gran intensidad.\n"));
SetIds(({"piedra","piedra preciosa","brillante piedra preciosa"}));
SetWeight(200);
SetValue(35000);
Set(P_GENDER,GENERO_FEMENINO);
Set(P_NUMBER,NUMERO_SINGULAR);
}