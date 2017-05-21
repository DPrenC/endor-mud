/*****************************************************/
//
//	"esc_mad"
//
//	escudo de madera AC: 3
//	11-12-01: Kodex -> Creaci�n
//	11-12-01: Kodex -> Modificaci�n
//
/******************************************************/
#include <combat.h>
#include <properties.h>
#include <materials.h>
#include "../path.h"
inherit ARMOUR;

create()
{
::create();

SetStandard(AT_SHIELD,3,P_SIZE_SMALL,M_MADERA);

SetShort("un escudo de madera");
SetLong(W("Es un peque�o escudo circular de madera "
"adornado con algo de hierro y con el s�mbolo de "
"un clan orco dibujado en el centro.\n"));
SetIds(({"escudo","escudo de madera"}));
SetWeight(QueryWeight()-1200);
Set(P_GENDER,GENERO_MASCULINO);
Set(P_NUMBER,NUMERO_SINGULAR);
SetNumberHands(1);
}