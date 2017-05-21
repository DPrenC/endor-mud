#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la avenida Grimly.");
   SetIntLong(
"En la mitad de la Avenida Grimly hay un callejon hacia el sur. Puedes visitar "
"los dos gremios de la ciudad marchando hacia el este o el oeste. Hay un cartel "
"en la pared.\n");

   AddDetail("cartel","Tiene algo escrito que tal vez podrias leer.\n");

   SetIntBright(80);
   SetIndoors(1);

   AddExit("sur",CIUDAD+"cruce1");
   AddExit("este",CIUDAD+"grimly7");
   AddExit("oeste",CIUDAD+"grimly5");

   SetLocate("Kha-annu");
}

init() {
   ::init();
   add_action("leer","leer");
}

leer(string str) {
   if (str != "cartel") {
      write("No hay nada que leer ahi.\n");
      return 1;
   }
   else {
write("Si el aliento del Dragon quieres probar, nuestra taberna deberas visitar.\n");
      return 1;
   }
}
