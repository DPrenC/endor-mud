/*   Lira para el quest de los titiriteros (Tinky)
     Creado por : Nemesis
     Fecha : 12-Dic-2001 14:20:18 CET
*/

#include <properties.h>
#include "./path.h"

inherit THING;

create() {
::create();
 SetShort("Una lira de madera");
 SetLong(W("Es una vieja lira de madera. Aunque está deteriorada, parece que "
           "todavía suena. Otra cosa es que suene bien...\n"));
 AddId(({"liraq","lira","lira de madera","vieja lira","vieja lira de madera"}));
 Set(P_NOGIVE,1);
 Set(P_NODROP,1);
 SetWeight(200);
 SetValue(50);
}
