/*
DESCRIPCION : calle junto a la puerta sur
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_00.c
MODIFICACION: 26-03-98 [Angor@Simauria] Creacion
              11-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <moving.h>

inherit ROOM;

//los PNJ no pasan
int ir_s()
{
if (TP->QueryIsPlayer()) return TP->move(Z_CIUDAD("puerta_s"),M_GO);
  return 1;
}

create() {
 ::create();
  SetPreIntShort("junto a");
 SetIntShort("la puerta sur");
 SetIntLong(
     "La entrada a la ciudad de Zarkam está formada por dos torres comunicadas entre "
     "sí por una pasarela elevada. Te hallas entre estas dos torres en el corredor que "
     "conduce al interior de la ciudad. Al sur están las dos inmensas puertas que "
     "controlan el acceso a la misma. En la torre que queda al este hay una puerta "
     "que permite acceder a las dependencias de la guardia de la ciudad.\n");

 AddDetail(({"puertas"}),
     "Las puertas son dos inmensas y macizas placas de metal. Permanecen abiertas "
     "siempre y cuando la ciudad no este bajo amenaza. Por su gran tamanyo juzgas que "
     "para moverlas o bien se necesitan varios orcos o se dispone de algun mecanisno "
     "mecanico que lo haga.\n");

  AddDetail(({"torre","torres"}),
     "Son dos torres de piedra con una altura de un pisos que forman la entrada de la "
     "ciudad de Zarkam. En ellas se aloja la guardia de soldados orcos que custodia la "
     "puerta. Ambas torres estan comunicadas por una pasarela. Al ser un lugar elevado "
     "son un buen sitio desde donde vigilar todo lo que ocurre en este valle.\n");

  AddDetail(({"pasarela","arco"}),
     "Entre las dos torres se extiende una pasarela que permite ir de una a la otra. "
     "La pasarela se halla sobre un arco de piedra que surge de las paredes de las dos "
     "torres que forman la puerta de la ciudad.\n");

  AddDetail(({"puerta","dependencias"}),
     "En la torre que queda al este una puerta permite acceder a su interior. Los "
     "soldados que custodian la puerta de la ciudad viven en estas torres.\n");

  AddDetail(({"guardia","guardias"}),
     "La puerta de la ciudad dispone de una guardia de soldados para controlar quien "
     "puede o no entrar a la ciudad. Los guardias, que se alojan en las torres de la "
     "puerta, suelen estar en el exterior de la ciudad controlando la entrada o en la "
     "parte alta de las torres vigilando lo que ocurre en el valle.\n");

  AddDetail(({"ciudad","ciudad fortificada","Zarkam","zarkam"}),
     "En medio del valle y sobre una loma se alza la ciudad fortificada de Zarkam. Es "
     "una poblacion de mediano tamanyo que se halla totalmente rodeado por una alta "
     "muralla de piedra. Desde el exterior, lo unico que se puedes ver de la ciudad es "
     "una alta torre que se alza sobre la muralla y en la que siempre hay vigias por "
     "si aparecen enemigos. Seguro que vigilan tus movimientos desde que entraste en "
     "este valle... No hay duda que esta gente esta acostumbrada a la guerra.\n");

SetIntNoise("Se oye el ajetreo tipico de una ciudad.\n");
SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
SetLocate("ciudad de Zarkam");
SetIndoors(0);

AddExit("norte",Z_CIUDAD("calle_01"));
AddExit("este",Z_CIUDAD("torre_00"));
AddExit("sur",SF(ir_s));
}

