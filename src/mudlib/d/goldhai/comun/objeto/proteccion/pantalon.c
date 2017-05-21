/****************************************************************************
Fichero: pantalon.c
Autor: Ratwor
Fecha: 17/04/2008
Descripción: unos pantalones.
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
	SetIds(({"pantalón","pantalon","pantalones"}));
	SetShort("unos pantalones de tela");
	Set(P_NUMBER, NUMBER_PLURAL);
	SetWeight(550);
	SetValue(3000);
	switch(d3()){
	    case 1:
	        SetShort("unos pantalones granates de terciopelo");
            SetLong("Se trata de unos pantalones de grueso terciopelo de color granate. "
            "De un corte sencillo  a la par que elegante.\n");
            break;
        case 2:
            SetShort("unos pantalones negros de terciopelo");
            SetLong("Se trata de unos pantalones de grueso terciopelo de color negro. De "
            "un corte sencillo  a la par que elegante.\n");
            break;
        case 3:
            SetShort("unos pantalones verdes de terciopelo");
            SetLong("Se trata de unos pantalones de grueso terciopelo de color verde "
            "botella. De un corte sencillo  a la par que elegante.\n");
            break;
	}
}
