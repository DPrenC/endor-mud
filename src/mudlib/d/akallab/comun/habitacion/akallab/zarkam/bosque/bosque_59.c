/*
DESCRIPCION  : Bosque al nordeste de Zarkam.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_??.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el bosque junto a la cordillera de Kova");
  SetIntLong(
  "Te encuentras en la zona limitrofe del bosque, los arboles no han podido "
  "seguir avanzando debido a la proximidad de la cordillera de Kova. Este "
  "camino transcurre entre las montanyas y el bosque, es un lugar muy poco "
  "concurrido debido a la dificultad que entranya circular por caminos tan "
  "angostos. "
  "Hacia el norte te puedes acercar todavia mas a las montanyas de Kova.\n");
  AddDetail(({"cordillera","Kova","montana","montanyas"}),
  "A tu lado se encuentra la cordillera de Kova. La pared rocosa de la montanya "
  "que tienes ante ti es extremadamente lisa e imposible de escalar incluso para "
  "los mas diestros.\n");
  AddDetail(({"arboles","arbol","bosque"}),
  "Te rodean los ultimos arboles del bosque, que no ha podido seguir avanzando "
  "debido a las montanyas. Al contemplar los arboles de cerca, compruebas que "
  "algunos tienen unas extranyas marcas rojas realizadas con un tinte que no "
  "logras reconocer.\n");
  AddExit("nordeste",Z_BOSQUE("bosque_64"));
  AddExit("norte",Z_BOSQUE("bosque_63"));
  AddExit("suroeste",Z_BOSQUE("bosque_51"));
  SetIndoors(0);
  SetIntSmell("El olor es el de la vegetacion del bosque.\n");
  SetIntNoise("Escuchas como caen pequenyas piedrecillas desde la montanya.\n");
  SetLocate("bosque de Zarkam");
}
