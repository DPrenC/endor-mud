
#include "path.h"
inherit WEAPON;

#include <properties.h>
#include <combat.h>

create(){

	::create();
	SetStandard(WT_VARA,6,P_SIZE_MEDIUM,M_MADERA);
	SetShort("la vara de Anakha");
	SetLong("Es una vara de fina madera de caoba. Suave al tacto, jalonada de pequeños trozos de un metal brillante que dotan a este arma de una potencia mortifera donde las haya... ¿o no?.\n");
	SetWeight(QueryWeight()+1000);
	SetIds(({"vara","vara de Anakha"}));
	Set(P_GENDER,GENERO_FEMENINO);
	Set(P_NUMBER,NUMERO_SINGULAR);
	SetNumberHands(2);

	}

emp(string str)
{
 if((str=="vara" || str=="vara de anakha") && TP->QueryAlign()<-10)
 	{
	tell_object(TP,"La vara de Anakha no puede ser blandida por un ser malvado.\n");
	return 1;
	}
 return 0;
}


init()
	{::init();
	 add_action("emp","empunyar");
	 add_action("emp","empuñar");
	}


