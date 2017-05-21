/* Espadon de plata
   Alura, 2/06/2001
*/

inherit WEAPON;
#include "path.h"
#include <properties.h>
#include <combat.h>

emp(string str)
{
 if((str=="espadon" || str=="espad�n" || str=="espad�n arg�nteo" || str=="espadon argenteo") && TP->QueryAlign()<-10)
        {
        tell_object(TP,"Este espad�n no puede ser blandido por un ser malvado.\n");
        return 1;
        }
 return 0;
}

miS(string str)
{
 if (str=="simbolos de espadon" || str=="s�mbolos de espad�n" || str=="simbolos del espadon" || str=="s�mbolos del espad�n")
 {
	tell_object(TP,"Parece que pone en com�n: Dehim te protege con esta arma de los muertos vivos.\n");
	return 1;
 }
	return 0;
}


create()
{
  ::create();
 SetStandard(WT_ESPADA, 12, P_SIZE_MEDIUM, M_PLATA);
  SetShort("un espad�n arg�nteo");
  SetLong("Es una espada bastante grande cuya hoja tiene grabados unos s�mbolos en la\n"
  "punta. El pomo es fino pero parece resistente. Tiene talladas unas hojas.\n");
  Set(P_NUMBER_HANDS, 2);
  SetIds(({"espadon","espad�n","espadon argenteo","espad�n arg�nteo"}));
  Set(P_GENDER, GENDER_MALE);
}


init()
        {::init();
         add_action("emp","empunyar");
         add_action("emp","empu�ar");
	 add_action("miS","examinar");
        }

