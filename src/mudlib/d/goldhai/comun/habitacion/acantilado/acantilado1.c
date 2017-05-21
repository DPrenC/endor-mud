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
Vas caminando por el borde de un inmenso acantilado. Desde aqui arriba hay\n\
una preciosa vista del mar el cual muere en una pequeña playa situada allá\n\
abajo y en donde yacen los restos de un gran barco. Puedes seguir caminando\n\
por el acantilado si vas en direccion Norte o bien quizás prefieras regresar\n\
al bosque, en ese caso debes ir hacia el Este.\n");

 AddDetail(({"acantilado","precipicio"}),
"Es un enorme acantilado que baja de forma casi perpendicular hasta una playa.\n\
Seria practicamente un suicidio saltar desde este lugar.\n");
 AddDetail(({"barco","gran barco","barco pirata"}),
"Parecen ser los restos de un gran barco pirata que por extrañas razones\n\
ha encallado en esta zona de Goldhai. Si consiguieras bajar hasta la playa\n\
es muy probable que aun encontrases dentro del barco los restos de algun botin.\n");
 AddDetail(({"mar","oceano","agua"}),
"Desde este punto de la isla el mar adquiere una belleza especial. Ves como\n\
llegan las olas de forma lenta y rompen a escasos metros de la playa.\n");
 AddDetail(({"playa","arena"}),
"Es una pequeña playa situada a los pies de este acantilado. Destaca sobre su\n\
arena un gran barco pirata encallado.\n");

 AddExit("norte",ACANTILADO("acantilado2"));
 AddExit("este",BOSCURO("frente_vudu"));

 SetLocate("acantilado del suroeste de Goldhai");
}