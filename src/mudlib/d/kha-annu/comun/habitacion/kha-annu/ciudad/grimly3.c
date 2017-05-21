#include "./path.h"

inherit KHA_ROOM;

create() {
   ::create();

   SetIntShort("la avenida Grimly.");
   SetIntLong(
"Sigues paseando por la gran Avenida Grimly, muy cerca de la zona donde se reunen "
"los gremios de Kha-Annu, en los cuales tal vez puedas aprender y entrenar "
"algunas habilidades.\n");

   SetIntBright(80);
   SetIndoors(1);

   AddExit("este",CIUDAD+"grimly4");
   AddExit("oeste",CIUDAD+"grimly2");

   SetLocate("Kha-annu");
}
