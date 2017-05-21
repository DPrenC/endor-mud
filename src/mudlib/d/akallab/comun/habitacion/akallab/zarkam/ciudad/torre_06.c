/*
DESCRIPCION : torre oeste de la puerta norte
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/torre_06.c
MODIFICACION: 12-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
 SetIntShort("la torre oeste de la puerta norte");
 SetIntLong(
"El primer piso de la torre, en el que te encuentras, sirve de dormitorio a los\n\
guardias de esta puerta de la ciudad. Junto a cada una de las literas que se\n\
hallan en este dormitorio se encuentra un gran arcon o baul y en la pared que\n\
queda al fondo de la habitacion hay un gran armario. Una puerta permite salir\n\
a la pasarela que comunica con la otra torre y una escalera de madera permite\n\
bajar a la planta baja.\n");

AddDetail(({"literas","litera","camas","cama"}),
 "Hay varias literas de madera en la habitacion colocadas junto a las paredes. "
 "Cada litera esta compuesta por dos camas, una sobre la otra, sobre las que "
 "hay jergones de paja y algunas mantas de lana.\n");

AddDetail(({"arcon","arcones","baul","baules"}),
 "Al pie de cada una de las literas de la habitacion hay un gran arcon o baul "
 "donde cada uno de los guardias tiene sus pertenecias personales. Los arcones "
 "estan cerrados con gruesos candados, signo de que sus propietarios no se fian "
 "demasiado...\n");

AddDetail(({"armario"}),
 "En la pared del fondo de la habitacion hay un gran armario de madera maciza. "
 "El armario esta cerrado y parece bastante robusto.\n");

AddDetail(({"pasarela","arco"}),
"Entre las dos torres se extiende una pasarela que permite ir de una a la otra. "
"La pasarela se halla sobre un arco de piedra que surge de las paredes de las dos "
"torres que forman la puerta de la ciudad.\n");

AddDetail(({"torre","torres"}),
 "Te encuentras en el interior de una de las dos torres que forman la entrada sur "
 "a la ciudad de Zarkam. Esta torre es una maciza construccion de piedra de dos "
 "pisos de altura donde se aloja la guardia de soldados orcos que custodia la "
 "puerta.\n");

AddDetail(({"escalera","barandilla"}),
 "Es una escalera de madera que permite bajar al piso inferior de esta torre donde "
 "se hallan el comedor y la cocina. La escalera dispone de una barandilla para "
 "evitar caidas.\n");

SetIntNoise("Oyes el murmullo de la ciudad a lo lejos.\n");
SetIntSmell("Esta habitacion no todo lo aireada que debiera..\n");
SetLocate("ciudad de Zarkam");
SetIndoors(1);
SetIntBright(50);

AddExit("abajo",Z_CIUDAD("torre_05"));
AddExit("este",Z_CIUDAD("torre_07"));
}
