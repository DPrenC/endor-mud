/*****************************************************/
//
//	"cimit"
//
//	cimitarra WC:5
//	11-12-01: Kodex -> Creaci�n
//	11-12-01: Kodex -> Modificaci�n
//
/******************************************************/

inherit WEAPON;

#include <combat.h>
#include <properties.h>
#include "../path.h"
create()
{
::create();

SetStandard(WT_ESPADA,5,P_SIZE_MEDIUM,M_HIERRO);

SetShort("una cimitarra");
SetLong(W("Es un sable curvado, su forma lo hace m�s"
" aerodin�mico que las espadas. Tiene muescas en la hoja "
"seguramente marcas de enemigos ca�dos, est� algo oxidada.\n"));
SetIds(({"arma","cimitarra"}));
SetWeight(QueryWeight() - 350);
Set(P_GENDER,GENERO_FEMENINO);
Set(P_NUMBER,NUMERO_SINGULAR);
SetNumberHands(1);
}