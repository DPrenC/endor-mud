#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la avenida del castillo");
   SetIntLong(
"De este a oeste continua la Avenida del Castillo.\n"
"Continuas viendo las lujas fachadas de las calles, las lujosas baldosas, "
"y las lujosas farolas. Se nota que aqui han trabajado los mejores artesanos "
"enanos. Justo al oeste esta la entrada al castillo, al este una tienda y al "
"norte hay una lujosa entrada cerrada.\n");

AddDetail( ({"farola","farolas"}),
"Son unas farolas de unos cuatro metros hechas de hierro puro, adornadas con "
"todo tipo de grabados y tallas tanto es su mastil como en el farol.\n"
"Su mision es la iluminacion de toda la ciudad\n");

   SetIntBright(80);
   SetIndoors(1);

   AddExit("este",CIUDAD+"avcastle8");
   AddExit("oeste",CIUDAD+"avcastle6");
   SetLocate("Kha-annu");
}
