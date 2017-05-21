/*****************************************************/
//
//	"punyo"
//
//	un puño de hierro WC: 4
//	me molaba la idea de hacer un WT_MANOPLA
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

SetStandard(WT_MANOPLA,4,P_SIZE_LARGE,M_HIERRO);

SetShort("un puño de hierro");
SetLong(W("Es un guante de hierro, recubierto por una malla por la"
" que sobresalen pequeños pinchos, no es un arma noble. Es utilizado "
"por clanes sombríos.\n"));
SetIds(({"arma","puño","punyo","puño de hierro","punyo de hierro"}));
SetWeight(QueryWeight());
Set(P_GENDER,GENERO_MASCULINO);
Set(P_NUMBER,NUMERO_SINGULAR);
SetNumberHands(1);
}