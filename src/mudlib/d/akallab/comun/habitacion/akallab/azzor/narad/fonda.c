/*
DESCRIPCION : fonda de Narad
FICHERO     : /d/akallab/comun/habitacion/azzor/narad/fonda.c
MODIFICACION: 24-02-99 [Angor@Simauria] Creacion
                       [woo] Adaptado al pub estandar.
--------------------------------------------------------------------------------
*/
#include "path.h"
#include AK_MACRO
inherit PUB;
create() {
 ::create();
 SetIntShort("la fonda 'El Ciervo Salvaje'");
 SetIntLong(
"Te encuentras en la fonda 'El Ciervo Salvaje', un pequeño pero acogedor lugar. "
"El local está regentado por Akton, un orco atento pero más bien serio que "
"atiende a la clientela, mientras que su esposa es la encargada de preparar las "
"estupendas comidas que aquí se sirven.\n");
 AddDetail(({"cocina","puerta"}),
 "En un extremo de la fonda hay una puerta que conduce a la cocina. Es "
   "allí donde se preparan las comidas que se sirven en la fonda. La puerta "
   "es de doble hoja con unos resortes que hacen que se cierre sola\n.");

 AddDetail(({"mesas"}),
 "La fonda esta llena de ellas. ¿Dónde sinó iban a comer los clientes?\n");

 AddDetail(({"chimenea"}),
 "Al fondo de la habitación hay una gran chimenea en la que siempre hay "
   "un agradable fuego que mantiene la fonda a una confortable temperatura.\n");

AddDetail(({"escalera"}),
"La escalera permite subir al piso de arriba donde viven los dueños.\n");


 SetLocate("valle de Azzor");
 AddExit("norte",NARAD("calle00"));
 AddFood("jabali asado","un plato de",12,15,0);
 AddFood("cordero al horno","un plato de",11,14,0);
 AddFood("guiso de ternera","un plato de",10,14,0);
 AddFood("pollo con patatas","un plato de",6,8,0);
 AddFood("sopa de verduras","un plato de",5,6,0);
 AddDrink("vino","un vaso de",4,5,5,0);
 AddDrink("vino especial","una jarra de",7,8,8,0);
 AddDrink("cerveza","una jarra de",7,6,10,0);
}
