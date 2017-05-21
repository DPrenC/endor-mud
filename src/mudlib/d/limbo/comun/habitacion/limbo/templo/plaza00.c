/*
DESCRIPCION  : Plaza del templo
FICHERO      : /d/limbo/comun/habitacion/limbo/templo/plaza00.c
MODIFICACION : 18-09-98 [Angor@Siamuria] Creacion.
               10-10-99 [Woo] Toqueteado...
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("la plaza del templo de Asthar");
  SetIntLong(
"Te encuentras al noroeste de la plaza del templo de Asthar junto al edificio de "
"los siervos de los dioses. Es este un edificio de dos plantas de altura donde "
"viven los siervos de los dioses y donde se encuentran algunos útiles servicios "
"para los recien llegados a este mundo. Al sur de la plaza se halla el templo de "
"Asthar y en el centro de la plaza un gran monolito de basalto negro.\n");

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
 "recien llegado encontrarás que en el hay servicios muy interesantes para ti.\n");

 AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
  "La isla Limbo es el lugar mágico de Simauria donde habitan los dioses. "
  "Gracias a ellos, es en este lugar donde las almas de los seres se "
  "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

 SetIntNoise("Oyes el ruido del las olas chocando contra los acantilados.\n");
 SetIntSmell("Hmm.. el aire es fresco y limpio.\n");
 SetLocate("isla Limbo");
 SetIndoors(0);

 AddExit("sur",TEMPLO("plaza03"));
 AddExit("este",TEMPLO("plaza01"));
}
