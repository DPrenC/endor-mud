/*
DESCRIPCION  : Cordillera de Kova
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/montain_8.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Rehecha
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("la cordillera de Kova");
  SetIntLong(
    "Estas montanyas son muy pedregosas, todo a tu alrededor es roca viva y no existe "
    "existe ningun tipo de vegetacion. Avanzar por esta zona es harto dificil ya que "
    "la roca que pisas es muy resbaladiza. Al pie de las montanyas se extiende el "
    "bosque en el que observas el río Zarmaii y una cabanya. Al sur de aqui la "
    "pendiente de la montanya se modera y podrias bajar hacia el bosque.\n");

  AddDetail(({"río","zarmaii","Zarmaii","afluente"}),
    "Al este ves el río Zarmaii, afluente del Kusaii. Puedes contemplarlo desde su "
    "nacimiento al norte, hasta que se pierde de vista por el sur.\n");

  AddDetail(({"cabanya"}),
    "Al este, y sobre el Zarmaii, ves una cabanya bastante grande que cruza el río "
    "de orilla a orilla.\n");

  AddDetail(({"roca","rocas"}),
    "Las rocas de esta montanya son altamente lisas lo que las hace bastante "
    "resvaladizas\n");

  AddDetail(({"bosque"}),"Ves como el bosque se extiende hacia el sur.\n");

  SetIntNoise("Reina el silencio.\n");
  SetIntSmell("El aire es algo frio en estas alturas.\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(0);

  //AddExit("abajo",Z_BOSQUE("bosque_51"));
  AddExit("norte",Z_BOSQUE("montain_6"));
  AddExit("oeste",Z_BOSQUE("montain_7"));
  AddExit("sur",Z_BOSQUE("montain_e"));
}

