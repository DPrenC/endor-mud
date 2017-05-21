/*****************************************************/
//
//	"cuero"
//
//	armadura de cuero tachonado, AC:12
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

SetStandard(AT_CORAZA,10,P_SIZE_MEDIUM,M_CUERO);

SetShort("una armadura de cuero tachonado");
SetLong(W("Es una coraza de cuero, con tachones metálicos"
" por su superficie haciendola más resistente que el cuero normal.\n"));
SetIds(({"armadura","coraza","armadura de cuero","armadura de cuero tachonado"}));
SetWeight(11000);
Set(P_GENDER,GENERO_FEMENINO);
Set(P_NUMBER,NUMERO_SINGULAR);
}