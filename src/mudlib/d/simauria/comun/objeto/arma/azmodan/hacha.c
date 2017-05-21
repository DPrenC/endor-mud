/*****************************************************/
//
//	"hacha"
//
//	hacha de batalla de ungrim a dos manos WC: 13
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

SetStandard(WT_HACHA,13,P_SIZE_MEDIUM,M_HIERRO);

SetShort("un hacha de batalla");
SetLong(W("Es un hacha enorme de doble hoja, demasiado pesada"
" como para controlarla a una mano. Lleva unas runas enanas "
"adornando el mango y está realmente afilada.\n"));
SetIds(({"arma","hacha","hacha de batalla"}));
SetWeight(QueryWeight() + 2000);
Set(P_GENDER,GENERO_FEMENINO);
Set(P_NUMBER,NUMERO_SINGULAR);

}