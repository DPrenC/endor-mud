/*****************************************************/
//
//	"espada_corta"
//
//	espada corta goblin, WC: 4
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

SetStandard(WT_ESPADA,4,P_SIZE_MEDIUM,M_HIERRO);

SetShort("una espada corta");
SetLong(W("Es una espada corta, su filo est� bastante carcomido"
" de la lucha pero a�n es un arma �til, es ligera y con la hoja "
"algo m�s larga que una daga.\n"));
SetIds(({"arma","espada","espada corta"}));
SetWeight(QueryWeight() -1000);
Set(P_GENDER,GENERO_FEMENINO);
Set(P_NUMBER,NUMERO_SINGULAR);
SetNumberHands(1);
}