#include "./path.h"
#include <properties.h>


inherit THING;

create() {
 ::create();
 AddId(({"llave1","llave1hum","llave","llave de la habitación humilde","llave de la habitacion humilde"}));
 SetAds(({"una","la"}));
 SetShort("la llave de la habitación humilde");
 SetLong(
"Es una llave de acero con un llavero plateado\n"
". Parece muy pesada.\n");
 SetWeight(1000);
 SetValue(25);
 Set(P_NODROP,
 "Grenel se enfadaría mucho contigo si tirases la llave.\n");
 Set(P_NOGIVE, "Grenel se enfadaría si lo haces.\n");
}
