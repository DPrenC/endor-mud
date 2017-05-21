/*
DESCRIPCION  : Plaza del templo
FICHERO      : /d/limbo/comun/habitacion/limbo/templo/plaza06.c
MODIFICACION : 16-09-98 [Angor@Siamuria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("la plaza del templo de Asthar");
  SetIntLong(
"Frente a ti se alza, imponente, la puerta de entrada al templo de Asthar al sur "
"de la plaza. El templo es un edificio impresionante coronado por una gigantesca "
"cupula semiesferica. Al oeste de la plaza se halla el edificio donde viven los "
"siervos de los dioses y en su centro un gran monolito.\n");

AddDetail(({"puerta","puerta del templo"}),
 "La puerta del templo esta formada por dos altas y pesadas hojas de un metal que "
 "parece plata. En ellas hay grabados multitud de intrincados dibujos y simbolos "
 "que te son totalmente desconocidos. Observas que hay 7 gemas incrustadas en la "
 "puerta que parecen brillar con luz propia. La puerta esta abierta.\n");

AddDetail(({"gema","gemas"}),
 "Las gemas estan incrustadas en la puerta y no hay forma de arrancarlas. Jurarias "
 "que brillan con una luz que emana de su interior, por extranyo que esto parezca.\n");

AddDetail(({"dibujos"}),
 "Las hojas de la puerta estan llenas de ellos. No sabes que pueden significar.\n");

AddDetail(({"templo","templo de Asthar"}),
 "El templo de Asthar es el edificio que se encuentra al sur de esta plaza. Es un "
 "gran edificio de base rectangular hecho de marmol de color claro sobre el sobre "
 "el que sobresale una inmensa boveda de forma hemisferica. En el templo, Asthar "
 "realiza la operacion que permite a un ser cambiar su forma fisica, manteniendo "
 "intacto su espiritu.\n");

AddDetail(({"edificio","siervos"}),
 "El edificio de los siervos de los dioses se halla al oeste de la plaza. Si eres "
 "un recien llegado encontraras que en el hay servicios muy interesantes para ti.\n");

AddDetail(({"plaza"}),
 "La plaza es una gran extension cuadrada de adoquines blancos en cuyo centro se "
 "halla un gran monolito de basalto negro.\n");

AddDetail(({"monolito"}),
 "Es un gran bloque de basalto. Acercate mas si quieres verlo mejor.\n");

 AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
  "La isla Limbo es el lugar magico de Simauria donde habitan los dioses. "
  "Gracias a ellos, es en este lugar donde las almas de los seres se "
  "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

 SetIntNoise("Oyes el ruido del las olas chocando contra los acantilados.\n");
 SetIntSmell("Hmm.. el aire es fresco y limpio.\n");
 SetLocate("isla Limbo");
 SetIndoors(0);

 AddExit("este",TEMPLO("plaza07"));
 AddExit("norte",TEMPLO("obelisco"));
 AddExit("oeste",TEMPLO("plaza05"));
 AddExit("sur",TEMPLO("templo01"));
}
