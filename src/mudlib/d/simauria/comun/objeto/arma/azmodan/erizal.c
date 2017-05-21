/*****************************************************/
//
//	"erizal"
//
//	erizal o garrote con pinchos WC: 9
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

SetStandard(WT_MAZA,9,P_SIZE_MEDIUM,M_HIERRO);

SetShort("un erizal");
SetLong(W("Es una gran maza de madera con pinchos met�licos "
"que le dan nombre, ideal para aplastar cr�neos y otras cosas peores...\n"));
SetIds(({"arma","maza","erizal"}));
SetDamType(DT_SLASH);
SetWeight(QueryWeight() + 200);
Set(P_GENDER,GENERO_MASCULINO);
Set(P_NUMBER,NUMERO_SINGULAR);
SetNumberHands(1);
}