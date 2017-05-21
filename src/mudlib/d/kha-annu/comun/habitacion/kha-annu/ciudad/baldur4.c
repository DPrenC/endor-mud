#include "./path.h"
inherit KHA_ROOM;
ir_norte() {
    write("El gremio de guerreros esta temporalmente cerrado por obras.\n");
    return 1;
}
create() {
   ::create();

   SetIntShort("la calle de Baldur");
   SetIntLong(
"Caminas por la calle de los gremios de Kha-annu, Baldur. Al norte se "
"encuentra el Gremio de Guerreros de Kha-annu, cuyo maestro es el antiguo "
"avatar de Kholiak, el guerrero Thualin. La entrada del gremio permanece "
"siempre abierta a recibir nuevos guerreros capaces de defender la capital "
"del reino. Dos maderos fijados a la puerta despiden un luminoso brillo "
"azulado y dan luz a esta parte del pasillo cavado en la montanya.\n"
);
   SetIntBright(80);
   SetIndoors(1);
   AddDetail(({"gremio","gremios"}),
"Hacia el norte esta la entrada al gremio de los guerreros y algo mas al este "
"puedes ver el gremio de clerigos.\n");
   AddDetail(
({"maderos","madero","antorcha","antorchas","brillo","luz"}),
"Son dos especie de antorchas, pero que no despiden gas ni llama alguna.\n");
AddExit("norte","/guilds/guerreros/sedes/kha-annu/sede_kha-annu");
   AddExit("este",CIUDAD+"baldur5");
   AddExit("oeste",CIUDAD+"baldur3");
   SetLocate("Kha-annu");
}