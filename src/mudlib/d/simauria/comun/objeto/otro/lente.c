/*   licencia de pescar
     Creado por : Cheto
     Fecha : 16-Nov-98
     Modificaciones:
     	 03-03-2003: [z] Hago que no se pueda robar.
*/

#include <properties.h>
inherit THING;

create() {
::create();
 SetShort("Una lente de faro");
 SetLong("Es la segunda lente más grande que has visto nunca.\n");
 AddId(({"lenteq","lente_faro","lente","lente de faro"}));
 Set(P_NOGIVE,1);
 Set(P_NODROP,1);
 Set(P_CANT_STEAL,1);
 SetWeight(100);
 SetValue(50000);
}
