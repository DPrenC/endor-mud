/*****************************************************/
//
//	"cota"
//
//	cota de anillas, AC:17
//	11-12-01: Kodex -> Creación
//	11-12-01: Kodex -> Modificación
//
/******************************************************/

inherit ARMOUR;

#include <materials.h>
#include <combat.h>
#include <properties.h>
#include "../path.h"

create()
{
::create();

SetStandard(AT_CORAZA,14,P_SIZE_LARGE,M_ACERO);

SetShort("una cota de anillas");
SetLong(W("Es una cota formada por anillas de acero entrelazadas formando"
" una malla, al no ser rígido proporciona más facilidad de movimiento "
"y por lo tanto una protección más fiable.\n"));
SetIds(({"cota","coraza","cota de anillas"}));
SetWeight(18000);
Set(P_GENDER,GENERO_FEMENINO);
Set(P_NUMBER,NUMERO_SINGULAR);
}