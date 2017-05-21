#include "path.h"
#include <moving.h>

/* Hay que cambiar estos define */

#define HAB_SIMPLE_HP "./habita1"
#define HAB_SIMPLE_SP "./habita2"
#define HAB_ESPECIAL  "./habita3"
inherit ROOM;

static int ir_sur();
static int ir_este();
static int ir_sureste();
static int ir_abajo();

create() {
   ::create();

  SetIntShort("la posada El Viajero");
  SetIntLong(
"Aqui es donde estan las habitaciones del primer piso. Hay una justo en frente y dos mas a\n"
"cada lado del pasillo. Las escaleras baja a la entrada de la posada y suben hasta un piso\n"
"superior.\n");
   SetIntBright(70);
   SetIndoors(1);

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

/* Faltan poner las rooms a las que van estas salidas */
  AddExit("arriba","./pasillo2");
  AddExit("abajo",SF(ir_abajo));
}

static int ir_sur() {
   if (!present("llave1",TP) ) {
     write("La puerta de la habitacion simple esta cerrada con llave.\n");
     return 1;
   }
   else {
      write("\nAbres la puerta de la habitacion simple... y entras.\n\n");
      TP->move(HAB_SIMPLE_HP,M_GO);
      return 1;
   }
}
static int ir_este() {
   if (!present("llave2",TP) ) {
     write("La puerta de la habitacion simple esta cerrada con llave.\n");
     return 1;
   } else {
     write("\nAbres la puerta de la habitacion simple... y entras.\n\n");
     TP->move(HAB_SIMPLE_SP,M_GO);
     return 1;
   }
}

static int ir_sureste() {
   if (!present("llave3",TP) ) {
     write("La puerta de la habitacion simple esta cerrada con llave.\n");
     return 1;
   } else {
     write("\nAbres la puerta de la habitacion simple... y entras.\n\n");
     TP->move(HAB_ESPECIAL,M_GO);
     return 1;
   }
}

static int ir_abajo() {
    tell_room(TCSUELO("./posada/privado1"),"Unos ligeros crugidos descienden por la escalera.\n");
    TP->move(TCSUELO("posada1"),M_GO);
    return 1;
}