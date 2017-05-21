#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la avenida del castillo");
   SetIntLong(
"Continuas por la avenida del castillo. Sus lujosas faloras iluminan la "
"calle y toda la ciudad practicamete. El castiillo esta mas al oeste, desde "
"aqui puedes ver la entrada un poco mas alla. Justo al norte parece que hay "
"una tienda, al este continua la avenida.\n");

AddDetail( ({"farola","farolas"}),
"Son unas farolas de unos cuatro metros hechas de hierro puro, adornadas con "
"todo tipo de grabados y tallas tanto es su mastil como en el farol.\n"
"Su mision es la iluminacion de toda la ciudad.\n");

   SetIntBright(80);
   SetIndoors(1);

   AddExit("norte",CIUDAD+"tiendas/tienda3");
   AddExit("este",CIUDAD+"avcastle9");
   AddExit("oeste",CIUDAD+"avcastle7");
   SetLocate("Kha-annu");
}
