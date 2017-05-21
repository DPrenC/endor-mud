/****************************************************************************
Fichero: falda.c
Autor: Ratwor
Fecha: 17/04/2008
Descripción: una falda.
****************************************************************************/

#include <combat.h>
#include <properties.h>
inherit ARMOUR;
create(){
	::create();
	switch(d2()){
	   case 1: SetStandard(AT_TROUSERS,1,P_SIZE_MEDIUM,M_TELA); break;
	    case 2: SetStandard(AT_TROUSERS,1,P_SIZE_SMALL, M_TELA); break;
	}
	SetIds(({"falda", "falda amplia", "amplia falda"}));
	switch(d2()){
	    case 1:
	        SetShort("una falda azul de raso");
            SetLong("Es una amplia falda realizada en suave raso azul marino. Es "
            "de confección elegante aunque sin ostentaciones.\n");
            break;
        case 2:
            SetShort("una falda granate de raso");
            SetLong("Es una amplia falda realizada en suave raso color Burdeos. Es "
            "de confección elegante aunque sin ostentaciones.\n");
            break;
	}
	SetWeight(1550);
	SetValue(3000);
}
