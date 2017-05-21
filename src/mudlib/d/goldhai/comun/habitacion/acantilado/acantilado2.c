
#include "./path.h"
inherit ACANTILADO("acantilado");

create()
{
 ::create();
 SetIndoors(0);
 SetIntShort("un acantilado");
 SetIntLong(
"Te has detenido justo en el borde de un acantilado. Miras hacia abajo y "
"observas como hay un enorme barco encallado en la playa con su estructura "
"casi intacta, quizás no haya pasado mucho tiempo desde que encalló... Desde "
"este lugar el acantilado parece menos escarpado y no tan peligroso, igual "
"con un poco de suerte puedes bajar.\n");

AddDetail(({"acantilado","precipicio"}),
"En este lugar el acantilado parece menos elevado y baja con una pequeña "
"pendiente. Quizás si encontraras algo con lo que sujetarte podrias bajar a "
"echar un vistazo al barco.\n");

AddDetail(({"barco","gran barco","barco pirata"}),
"Parecen ser los restos de un gran barco pirata que por extrañas razones "
"ha encallado en esta zona. Si consiguieras bajar hasta la playa quizá "
"encontrases dentro del barco los restos de algun botín.\n");

AddDetail(({"mar","oceano","agua"}),
"Desde este punto de la isla el mar adquiere una belleza especial. Ves como "
"llegan las olas de forma lenta y rompen a escasos metros de la playa.\n");

AddDetail(({"playa","arena"}),
"Es una pequeña playa situada a los pies de este acantilado. Destaca sobre su "
"arena un gran barco pirata encallado.\n");

AddItem(OTRO("roca_acantilado"),REFRESH_REMOVE);

AddExit("norte",ACANTILADO("acantilado3"));
AddExit("sur",ACANTILADO("acantilado1"));

SetLocate("acantilado del suroeste de Goldhai");
}