/*    Archivo posada.c
      Descripcion : posada COPIADA del pueblo de Krigor
      Modificacion: Bomber creacion 03-12-01
  */

#include <properties.h>
#include "./path.h"

inherit PUB;

create() {
::create();
SetIntShort("la posada");
SetLocate("???");
SetIntLong(W("Estas en una pequeña posada perdida en medio del bosque. "
           "En el lado norte de la habitación hay una pequeña barra para "
           "que los viajeros sedientos puedan saciar su sed, aunque hace "
           "mucho tiempo que solo la frecuentan los parroquianos de la zona. "
           "Tras la barra ves una pequeña cocina, y el resto de la sala esta "
           "lleno de mesas, todas ellas bastantes mugrientas y sucias. "
           "En un lado de la barra puedes ver lo que parece ser un menu."));
SetIndoors(1);
SetIntBright(45);
SetIntNoise("El sonido de risas y voces es muy fuerte.\n");
SetIntSmell("Un olor a comida sale de la cocina.\n");
AddExit("sur","plaza");
AddFood("estofado de ternera","un plato de",9,12,150);
AddFood("sopa de verduras","un plato de",7,8,100);
AddDrink("cerveza","una jarra de",3,4,8,100);
}

