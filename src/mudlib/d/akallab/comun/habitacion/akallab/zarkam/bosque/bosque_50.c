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
  "seguir avanzando debido a la proximidad de la cordillera de Kova. Por lo "
  "tanto al norte te impide el paso la propia cordillera, y al sur lo hacen los "
  "arboles que forman el bosque. "
  "Es un lugar muy estrecho que discurre hacia el este y que se interna en el "
  "bosque hacia el suroeste o en un claro hacia el noroeste.\n");
  AddDetail(({"cordillera","Kova","montana","montanyas"}),
  "Al norte se encuentra la cordillera de Kova. La pared rocosa de la montanya "
  "que tienes ante ti es extremadamente lisa e imposible de escalar incluso para "
  "los mas diestros.\n");
  AddDetail(({"arboles","arbol","bosque"}),
  "Al sur ves los ultimos arboles del bosque, que no ha podido seguir avanzando "
  "debido a las montanyas. Al contemplar los arboles de cerca, compruebas que "
  "algunos tienen unas extranyas marcas rojas realizadas con un tinte que no "
  "logras reconocer.\n");
  AddDetail(({"claro"}),
  "Al noroeste se abre un claro libre de vegetacion, rocas y arboles.\n");
  AddExit("este",Z_BOSQUE("bosque_51"));
  AddExit("noroeste",Z_BOSQUE("bosque_58"));
  AddExit("suroeste",Z_BOSQUE("bosque_39"));
  SetIndoors(0);
  SetIntSmell("El olor es el de la vegetacion del bosque.\n");
  SetIntNoise("Escuchas como caen pequenyas piedrecillas desde la montanya.\n");
  SetLocate("bosque de Zarkam");
}
