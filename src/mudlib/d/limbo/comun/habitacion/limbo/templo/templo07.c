/*
DESCRIPCION  : Templo de Asthar junto a las ventanas.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/templo07.c
MODIFICACION : 08-02-98 [angor] Creacion.
               24-08-98 [Angor@Simauria] Rehecha en gran medida
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el sudeste del templo de Asthar");
  SetIntLong(
"Te encuentras en la esquina sudeste del templo de Asthar. A traves de los altos "
"ventanales que hay en el muro este del templo, situado sobre el borde del "
"acantilado, puedes comtemplar el oceano y parte de la costa este de la isla. Al "
"oeste de aqui se alza majestuoso un altar elevado en el que tienen lugar las "
"intervenciones divinas de Asthar. Una escalinata permite subir al mismo.\n");

AddDetail(({"altar","altar"}),
"El altar es una especie de mesa situada sobre una plataforma elevada que se "
"encuentra al oeste de aqui. Es en el donde Asthar realiza el rito sagrado que "
"permite encarnarse a los espiritus o cambiar la forma de un cuerpo.\n");

AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
"La isla Limbo es el lugar magico de Simauria donde habitan los dioses. Gracias "
"a ellos, es en este lugar donde las almas de los seres se encarnan para poder "
"asi vivir en este mundo.\n");

AddDetail(({"ventana","ventanal","ventanales","oceano","acantilado","rocas","olas","acantilados"}),
"Por el dia, la luz entra en forma de grandes y difusos haces a traves de los "
"altos ventanales situados en la pared este del templo de Asthar iluminando su "
"interior. A traves de ellos puedes ver el oceano y parte de la costa este de la "
"isla Limbo. Cuando te asomas te das cuenta de que el edificio se halla "
"construido junto al borde de los acantilados que forman la costa de la isla, de "
"forma sientes vertigo al darte cuenta que te hallas a mucho metros por encima de "
"las rocas donde rompen furiosamente las olas del mar.\n");

SetIntNoise("Oyes el ruido del las olas chocando contra los acantilados.\n");
SetIntSmell("Hmm.. el aire es fresco y limpio.\n");
SetLocate("isla Limbo");
SetIndoors(1);
SetIntBright(50);


AddExit("norte",TEMPLO("templo05"));
AddExit("oeste",TEMPLO("altar"));
}

