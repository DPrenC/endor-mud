#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la avenida Grimly.");
   SetIntLong(
"Estas el este de uno de los gremios de Kha-annu. Al oeste hay un cruce hacia el "
"sur y la Avenida parece no acabarse nunca.\n");

   SetIntBright(80);
   SetIndoors(1);

   AddExit("este",CIUDAD+"grimly6");
   AddExit("oeste",CIUDAD+"grimly4");

   SetLocate("Kha-annu");
}
