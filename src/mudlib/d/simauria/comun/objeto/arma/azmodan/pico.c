/*****************************************************/
//
//	"pico"
//
//	es solo un pico, he puesto cuchillo para que
//	todo el mundo pueda llevarlo WC: 1
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

SetStandard(WT_CUCHILLO,1,P_SIZE_GENERIC,M_HIERRO);

SetShort("un viejo pico");
SetLong(W("Es un viejo pico utilizado antiguamente para picar en "
"las minas.\n"));
SetIds(({"pico","viejo pico"}));
Set(P_GENDER,GENERO_FEMENINO);
Set(P_NUMBER,NUMERO_SINGULAR);
SetNumberHands(1);
}
