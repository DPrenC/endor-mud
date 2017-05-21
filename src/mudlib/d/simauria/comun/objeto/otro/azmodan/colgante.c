/***********************************************************/
//	"colgante"
//	Colgante de huesos para maldecir
//	27-11-01 : Creación -> Kodex
//	27-11-01 : Modificación -> Kodex
//
//
inherit ARMOUR;
#include <combat.h>
#include <properties.h>
#include "./path.h"
create()
{
::create();
SetStandard(AT_AMULET,0,P_SIZE_GENERIC,M_HUESO);
SetShort("un colgante de huesos");
SetLong(W("Es un colgante fabricado con huesos, utilizado"
" en magia negra y ritos ocultos.\n"));
SetIds(({"colgante","colgante de huesos"}));
SetWeight(200);
Set(P_GENDER,GENERO_MASCULINO);
Set(P_NUMBER,NUMERO_SINGULAR);
Set(P_NOSELL);
}