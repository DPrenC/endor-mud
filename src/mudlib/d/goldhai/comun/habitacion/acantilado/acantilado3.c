/*=============================================================*
 |         << GOLDHAI.Acantilado [w] Woo@simauria >>           |
 *=============================================================*
 |            Creacion.................. 29-10-98              |
 |            Ultima Modificacion....... 08-02-99              |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit ACANTILADO("acantilado");

create()
{
 ::create();
 SetIndoors(0);
 SetIntShort("un acantilado");
 SetIntLong("\
Estas al borde de uno de los tantos acantilados que existen en la isla de\n\
Goldhai. Destaca en el lugar un gran barco pirata que parece estar encallado\n\
en la playa. Este es un bonito sitio para mirar el mar pero si no deseas\n\
permanecer aqui mucho más tiempo siempre puedes ir al bosque en dirección Este\n\
o bien continuar recorriendo el acantilado hacia el Sur.\n");

 AddDetail(({"acantilado","precipicio"}),
"Es un enorme acantilado que baja de forma casi perpendicular hasta una playa.\n\
Seria practicamente un suicidio saltar desde este lugar.\n");
 AddDetail(({"barco","gran barco","barco pirata"}),
"Parecen ser los restos de un gran barco pirata que por extrañas razones\n\
ha encallado en esta zona de Goldhai. Si consiguieras bajar hasta la playa\n\
es muy probable que aún encontrases dentro del barco los restos de algun botin.\n");
 AddDetail(({"mar","oceano","agua"}),
"Desde este punto de la isla el mar adquiere una belleza especial. Ves como\n\
llegan las olas de forma lenta y rompen a escasos metros de la playa.\n");
 AddDetail(({"playa","arena"}),
"Es una pequeña playa situada a los pies de este acantilado. Destaca sobre su\n\
arena un gran barco pirata encallado.\n");

 AddExit("este",BOSCURO("bosque9"));
 AddExit("sur",ACANTILADO("acantilado2"));

 SetLocate("acantilado del suroeste de Goldhai");
}