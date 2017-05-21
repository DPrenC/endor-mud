/* Espadon de plata
   Alura, 2/06/2001
*/

inherit WEAPON;
#include "path.h"
#include <properties.h>
#include <combat.h>

emp(string str)
{
 if((str=="espadon" || str=="espadón" || str=="espadón argénteo" || str=="espadon argenteo") && TP->QueryAlign()<-10)
        {
        tell_object(TP,"Este espadón no puede ser blandido por un ser malvado.\n");
        return 1;
        }
 return 0;
}

miS(string str)
{
 if (str=="simbolos de espadon" || str=="símbolos de espadón" || str=="simbolos del espadon" || str=="símbolos del espadón")
 {
	tell_object(TP,"Parece que pone en común: Dehim te protege con esta arma de los muertos vivos.\n");
	return 1;
 }
	return 0;
}


create()
{
  ::create();
 SetStandard(WT_ESPADA, 12, P_SIZE_MEDIUM, M_PLATA);
  SetShort("un espadón argénteo");
  SetLong("Es una espada bastante grande cuya hoja tiene grabados unos símbolos en la\n"
  "punta. El pomo es fino pero parece resistente. Tiene talladas unas hojas.\n");
  Set(P_NUMBER_HANDS, 2);
  SetIds(({"espadon","espadón","espadon argenteo","espadón argénteo"}));
  Set(P_GENDER, GENDER_MALE);
}


init()
        {::init();
         add_action("emp","empunyar");
         add_action("emp","empuñar");
	 add_action("miS","examinar");
        }

