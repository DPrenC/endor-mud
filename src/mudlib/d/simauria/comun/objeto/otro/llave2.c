#include "./path.h"
#include <properties.h>


inherit THING;

create() {
 ::create();
 AddId(({"llave2","llave2nob","llave","llave de la habitacion noble"}));
 SetAds(({"una","la"}));
 SetShort("la llave de la habitación noble");
 SetLong(
"Es una llave de acero, de la que cuelga un llavero dorado\n"
"en el que pone el nombre de la posada.\n");
 SetWeight(600);
 SetValue(50);
 Set(P_NODROP,
 "Grenel se enfadaría mucho contigo si tirases la llave.\n");
 Set(P_NOGIVE, "Grenel se enfadaría si lo haces.\n");
}
