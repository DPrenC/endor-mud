#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la avenida del castillo, cruze con Keniah");
   SetIntLong(
"Aqui la avenida del castillo forma una T con la calle Keniah.\n"
"Puedes apreciar que la avenida del castillo es mucho mas lujosa que "
"la otra calle. Sin duda es una de las avenidas mas importantes de "
"Kha-annu. Las faloras alumbran lujosamente la ciudad, que aun estando "
"bajo tierra, nunca se encuentra a oscuras.\n"
"El castillo que da nombre a esta avenida se encuentra al oeste de aqui.\n");

AddDetail( ({"farola","farolas"}),
"Son unas farolas de unos cuatro metros hechas de hierro puro, adornadas con "
"todo tipo de grabados y tallas tanto es su mastil como en el farol.\n"
"Su mision es la iluminacion de toda la ciudad\n");

   SetIntBright(80);
   SetIndoors(1);

   AddExit("sur",CIUDAD+"keniah9");
   AddExit("este",CIUDAD+"avcastle10");
   AddExit("oeste",CIUDAD+"avcastle8");
   SetLocate("Kha-annu");
}
