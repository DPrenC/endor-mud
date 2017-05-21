/*
DESCRIPCION  : Plaza del templo
FICHERO      : /d/limbo/comun/habitacion/limbo/templo/plaza05.c
MODIFICACION : 19-09-98 [Angor@Siamuria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;


create() {
  ::create();
  SetIntShort("la plaza del templo de Asthar");
  SetIntLong(
"Estas en la esquina suroeste de la plaza del templo de Asthar. Frente a ti se "
"alzan al sur el impresionante edificio del templo y al oeste otro en el que "
"viven los siervos de los dioses que habitan en esta isla y donde se encuentran "
"algunos utiles servicios para los recien llegados a este mundo. En el centro de "
"la plaza se encuentra un gran monolito de basalto negro.\n");

AddDetail(({"templo","templo de Asthar"}),
 "El templo de Asthar es el edificio que se encuentra al sur de esta plaza. Es un "
 "gran edificio de base rectangular hecho de marmol de color claro sobre el sobre "
 "el que sobresale una inmensa boveda de forma hemisferica. En el templo, Asthar "
 "realiza la operacion que permite a un ser cambiar su forma fisica, manteniendo "
 "intacto su espiritu.\n");

AddDetail(({"plaza"}),
 "La plaza es una gran extension cuadrada de adoquines blancos en cuyo centro se "
 "halla un gran monolito de basalto negro.\n");

AddDetail(({"monolito"}),
 "Es un gran bloque de basalto. Acercate mas si quieres verlo mejor.\n");

AddDetail(({"edificio","siervos"}),
 "El edificio de los siervos de los dioses se halla al oeste aqui. Si eres un "
 "recien llegado encontraras que en el hay servicios muy interesantes para ti.\n");

 AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
  "La isla Limbo es el lugar magico de Simauria donde habitan los dioses. "
  "Gracias a ellos, es en este lugar donde las almas de los seres se "
  "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

 SetIntNoise("Oyes el ruido del las olas chocando contra los acantilados.\n");
 SetIntSmell("Hmm.. el aire es fresco y limpio.\n");
 SetLocate("isla Limbo");
 SetIndoors(0);

 AddExit("norte",TEMPLO("plaza03"));
 AddExit("este",TEMPLO("plaza06"));
}
