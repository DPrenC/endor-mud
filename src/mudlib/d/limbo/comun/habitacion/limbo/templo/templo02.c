/*
DESCRIPCION  : Templo de Asthar junto a las ventanas.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/templo02.c
MODIFICACION : 08-02-98 [angor] Creacion.
               24-08-98 [Angor@Simauria] Rehecha en gran medida
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;


create() {
  ::create();
  SetIntShort("el nordeste del templo de Asthar");
  SetIntLong(
"Te hallas en la esquina nordeste del templo de Asthar. En el muro este del "
"templo, situado sobre el borde del acantilado, se encuentran una serie de altos "
"ventanales a traves de los cuales puedes comtemplar el oceano y parte de la "
"costa este de la isla. Varias hileras de columnas recorren el interior del "
"templo soportando el peso de su boveda. Al sur del templo se halla el altar "
"donde Asthar resucita a los desventurados seres que han muerto en este mundo.\n");

AddDetail(({"columna","columnas"}),
"Varias hileras de columnas recorren el interior del templo. Su funcion es la de "
"soportar el peso de la inmensa boveda semiesferica que corona el templo. Las "
"columnas son delgadas y estan fabricadas a partir de bloques de un marmol megro. "
"Estan casi totalmente cubiertas por una serie de complicados dibujos y signos "
"que te son completamente desconocidos.\n");

AddDetail(({"dibujos","signos"}),
"Las columnas del templo estan casi totalmente cubiertas con ellos. No tienes ni "
"idea de que son o que representan.\n");

AddDetail(({"boveda","esfera"}),
 "Ocupando la mayor parte del techo del templo se halla una inmensa boveda de "
"forma semiesferica. Tal vez sea un efecto optico, pero te parece que, flotando "
"alla arriba en la boveda hay una gran esfera de luz...\n");

AddDetail(({"altar","altar"}),
"El altar es una especie de mesa situada sobre una plataforma elevada que se "
"encuentra al sur del templo. Es en el donde Asthar realiza el rito sagrado que "
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

AddExit("sur",TEMPLO("templo05"));
AddExit("oeste",TEMPLO("templo01"));
}
