#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la avenida del castillo");
   SetIntLong(
"Esta es una de las partes mas solitarias de la avenida del castillo puesto "
"que todo el barullo se centra en al oeste, en la parte del castillo.\n"
"Al norte hay un callejon que parece comunicar con otra calle paralela, "
"al este parece que se acaba la calle un poco mas alla.\n");

AddDetail( ({"farola","farolas"}),
"Son unas farolas de unos cuatro metros hechas de hierro puro, adornadas con "
"todo tipo de grabados y tallas tanto es su mastil como en el farol.\n"
"Su mision es la iluminacion de toda la ciudad\n");

   SetIntBright(80);
   SetIndoors(1);

   AddExit("norte",CIUDAD+"callejon10");
   AddExit("este",CIUDAD+"avcastle11");
   AddExit("oeste",CIUDAD+"avcastle9");
   SetLocate("Kha-annu");
}
