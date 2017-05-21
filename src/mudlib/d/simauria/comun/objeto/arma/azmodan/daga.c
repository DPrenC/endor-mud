/*****************************************************/
//
//	"daga"
//
//	Daga ritual, WC: 3
//	11-12-01: Kodex -> Creación
//	11-12-01: Kodex -> Modificación
//
/******************************************************/
inherit WEAPON;

#include <combat.h>
#include <properties.h>
#include "../path.h"
create()
{
::create();

SetStandard(WT_CUCHILLO,3,P_SIZE_MEDIUM,M_HIERRO);

SetShort("una daga ritual");
SetLong(W("Al mirar la daga ritual ves una daga corroida, lo mas"
" seguro es que sea por la sangre que haya corrido por el filo. "
"Aun se puede ver los pocos restos secos en los huecos de las runas.\n"));
SetIds(({"arma","daga","daga ritual"}));
Set(P_GENDER,GENERO_FEMENINO);
Set(P_NUMBER,NUMERO_SINGULAR);
SetNumberHands(1);
}