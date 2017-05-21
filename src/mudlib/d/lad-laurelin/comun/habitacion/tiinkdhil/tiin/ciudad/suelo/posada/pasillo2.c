#include "path.h"

/* Hay que cambiar estos define */

;
#define HAB_LUJO_HP  "./habita4"
#define HAB_LUJO_SP  "./habita5"
#define HAB_ESPECIAL "./habita6"
inherit ROOM;

static int ir_sur();
static int ir_este();
static int ir_sureste();


create() {
   ::create();

  SetIntShort("la posada El Viajero");
  SetIntLong(
"Aqui es donde estan las habitaciones del primer piso. Hay una justo en frente y dos mas a\n"
"cada lado del pasillo. Las escaleras baja a la entrada de la posada y suben hasta un piso\n"
"superior.\n");
   SetIntBright(70);
   SetIndoors(1);
   SetLocate("posada");

  AddDetail(({"habitaciones"}),
"Hay tres habitaciones y te fijas que desde la habitacion del sureste viene un ligero aroma.\n");
   AddDetail(({"alfombra","gran alfombra"}),
"La alfombra cubre el pasillo y seguramente las habitaciones.\n");
   AddDetail(({"escaleras"}),
"Las escaleras quedan justo detras del pasillo.\n"
"Llevan al primer piso.\n");
  AddExit("sur",SF(ir_sur));
  AddExit("sureste",SF(ir_sureste));
  AddExit("este",SF(ir_este));
  AddExit("abajo","./pasillo1");
}

int ir_sur() {
   if (!present("llave4",TP) ) {
     write("La puerta de la habitacion de lujo esta cerrada con llave.\n");
     return 1;
   }
   else {
      write("\nAbres la puerta de la habitacion de lujo... y entras.\n\n");
      TP->move(HAB_LUJO_HP,M_GO);
      return 1;
   }
}

int ir_este() {
   if (!present("llave5",TP) ) {
     write("La puerta de la habitacion de lujo esta cerrada con llave.\n");
     return 1;
   } else {
     write("\nAbres la puerta de la habitacion de lujo... y entras.\n\n");
     TP->move(HAB_LUJO_SP,M_GO);
     return 1;
   }
}

int ir_sureste() {
   if (!present("llave6",TP) ) {
     write("La puerta de la habitacion de lujo esta cerrada con llave.\n");
     return 1;
   } else {
     write("\nAbres la puerta de la habitacion de lujo... y entras.\n\n");
     TP->move(HAB_ESPECIAL,M_GO);
     return 1;
   }
}
