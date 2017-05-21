/*****************************************************/
//
//	"punyo"
//
//	un pu�o de hierro WC: 4
//	me molaba la idea de hacer un WT_MANOPLA
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

SetStandard(WT_MANOPLA,4,P_SIZE_LARGE,M_HIERRO);

SetShort("un pu�o de hierro");
SetLong(W("Es un guante de hierro, recubierto por una malla por la"
" que sobresalen peque�os pinchos, no es un arma noble. Es utilizado "
"por clanes sombr�os.\n"));
SetIds(({"arma","pu�o","punyo","pu�o de hierro","punyo de hierro"}));
SetWeight(QueryWeight());
Set(P_GENDER,GENERO_MASCULINO);
Set(P_NUMBER,NUMERO_SINGULAR);
SetNumberHands(1);
}