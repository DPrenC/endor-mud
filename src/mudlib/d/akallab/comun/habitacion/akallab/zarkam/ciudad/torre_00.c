/*
DESCRIPCION : torre este de la puerta sur
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/torre_00.c
MODIFICACION: 27-03-98 [Angor@Simauria] Creacion
              11-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
 SetIntShort("la torre este de la puerta sur");
 SetIntLong(
"Te hallas en el interior de la torre este de la puerta sur de la ciudad, donde\n\
viven los guardias de la puerta. Al fondo de la habitacion un lento fuego\n\
crepita sobre el hogar calentando una olla. A ambos lados del hogar hay dos\n\
largos bancos y en el centro de la habitacion hay varias mesas donde comer.\n\
Al fondo de la habitacion una escalera de madera permite subir al piso superior.\n");

AddDetail(({"fuego","hogar","lumbre","chimenea"}),
 "Al fondo de la habitacion hay una pequenya chimenea bajo la que se encuentra un "
 "lento fuego. Es un fuego pequenyo y escaso, pero suficiente para calentar "
 "continuamente la olla que cuelga sobre el.\n");

AddDetail(({"olla","comida"}),
 "Colgando sobre la lumbre hay una gran olla de metal un poco abollada. En ella se "
 "esta cocinando la proxima comida de los guardias. El olor que sale de ella es "
 "tentador.\n");

AddDetail(({"bancos","banco"}),
 "A los lados de las mesas hay unos largos bancos de madera donde sentarse a la "
 "hora de comer. Junto al hogar hay ademas otro par de bancos que permiten "
 "calentarse al calor del fuego, lo cual se agradece mucho especialmente tras una "
 "larga y fria guardia nocturna.\n");

AddDetail(({"mesa","mesas"}),
 "Hay varias largas mesas en el centro de la habitacion. A cada lado de ellas un "
 "largo banco permite sentarse a los comensales a la hora de la comida. Sobre las "
 "mesas aun hay restos de la ultima comida por recoger.\n");

AddDetail(({"torre","torres"}),
 "Te encuentras en el interior de una de las dos torres que forman la entrada sur "
 "a la ciudad de Zarkam. Esta torre es una maciza construccion de piedra de dos "
 "pisos de altura donde se aloja la guardia de soldados orcos que custodia la "
 "puerta.\n");

AddDetail(({"escalera","barandilla"}),
 "Es una escalera de madera que permite subir al piso superior de esta torre donde "
 "probablemente se halle el dormitorio de los guardias. La escalera dispone de una "
 "barandilla para evitar caidas.\n");

AddDetail(({"guardia","guardias"}),
 "La puerta de la ciudad dispone de una guardia de soldados para controlar quien "
 "puede o no entrar a la ciudad. Los guardias, que se alojan en las torres de la "
 "puerta, suelen estar en el exterior de la ciudad controlando la entrada o en la "
 "parte alta de las torres vigilando lo que ocurre en el valle.\n");

SetIntNoise("Las brasas del fuego crepitan lastimeramente.\n");
SetIntSmell("El aire es calido y el olor de la olla tentador...\n");
SetLocate("ciudad de Zarkam");
SetIndoors(1);
SetIntBright(50);

AddExit("arriba",Z_CIUDAD("torre_01"));
AddExit("oeste",Z_CIUDAD("calle_00"));
}