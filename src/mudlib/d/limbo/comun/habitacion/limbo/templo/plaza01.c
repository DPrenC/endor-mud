/*
DESCRIPCION  : Plaza del templo
FICHERO      : /d/limbo/comun/habitacion/limbo/templo/plaza01.c
MODIFICACION : 19-09-98 [Angor@Siamuria] Creacion.
               10-10-99 [Woo] Toqueteado...
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;


create() {
  ::create();
  SetIntShort("la plaza del templo de Asthar");
  SetIntLong(
"La plaza del templo de Asthar se extiende ante ti. Te hallas al norte de la "
"misma junto al inicio de un camino que parte de ella y se aleja hacia el centro "
"de esta isla. Al sur de la plaza observas el impresionante edificio del templo, "
"y al oeste otro en el que viven los siervos de los dioses. En el medio de esta "
"amplia plaza de adoquines blancos se halla un gran monolito de basalto negro.\n");

AddDetail(({"templo","templo de Asthar"}),
 "El templo de Asthar es el edificio que se encuentra al sur de esta plaza. Es un "
 "gran edificio de base rectangular hecho de mármol de color claro sobre el sobre "
 "el que sobresale una inmensa bóveda de forma hemisférica. En el templo, Asthar "
 "realiza la operación que permite a un ser cambiar su forma física, manteniendo "
 "intacto su espíritu.\n");

AddDetail(({"plaza"}),
 "La plaza es una gran extensión cuadrada de adoquines blancos en cuyo centro se "
 "halla un gran monolito de basalto negro.\n");

AddDetail(({"monolito"}),
 "Es un gran bloque de basalto. Acercate más si quieres verlo mejor.\n");

AddDetail(({"edificio","siervos"}),
 "El edificio de los siervos de los dioses se halla al oeste aquí. Si eres un "
 "recien llegado encontrarás que en él hay servicios muy interesantes para ti.\n");

 AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
  "La isla Limbo es el lugar mágico de Simauria donde habitan los dioses. "
  "Gracias a ellos, es en este lugar donde las almas de los seres se "
  "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

 SetIntNoise("Oyes el ruido del las olas chocando contra los acantilados.\n");
 SetIntSmell("Hmm.. el aire es fresco y limpio.\n");
 SetLocate("isla Limbo");
 SetIndoors(0);

 AddExit("norte",LIMBO("alameda02"));
 AddExit("sur",TEMPLO("obelisco"));
 AddExit("oeste",TEMPLO("plaza00"));
 AddExit("este",TEMPLO("plaza02"));
}
