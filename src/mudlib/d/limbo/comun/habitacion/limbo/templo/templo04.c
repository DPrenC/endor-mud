/*
DESCRIPCION  : Centro del Templo de Asthar
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/templo04.c
MODIFICACION : 07-02-98 [Angor@Simauria] Creacion.
               24-08-98 [Angor@Simauria] Rehecha en gran medida
               24-03-99 [Angor@Simauria] wrapeada...
               10-10-99 [Woo] Toqueteada...
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <moving.h>

inherit ROOM;

#define NOMBRE (capitalize(TP->QueryName()))

create() {
  ::create();
  SetIntShort("el centro del templo de Asthar");
  SetIntLong(  "Te hallas en el centro del Templo de Asthar, justo debajo de la inmensa "
    "bóveda semiesférica que lo corona soportada por altas columnas. El muro oeste está recubierto de murales "
    "pintados y en el del este se abren unos altos ventanales. Al sur se "
    "halla el altar donde Asthar resucita a los espiritus de aquellos seres que han muerto en este mundo.\n");

AddDetail(({"boveda","bóveda"}),
"Ocupando la mayor parte del techo del templo se halla una inmensa bóveda de "
"forma semiesférica, que se encuentra soportada por delgadas columnas de mármol negro dispuestas en varias hileras.\n");

AddDetail(({"columna","columnas"}),
"Varias hileras de columnas recorren el interior del templo. Su función es la de "
"soportar el peso de la inmensa bóveda semiesférica que corona el templo. Las "
"columnas son delgadas y están fabricadas a partir de bloques de un marmol negro. "
"Están casi totalmente cubiertas por una serie de complicados dibujos y signos "
"que te son completamente desconocidos.\n");

AddDetail(({"dibujos","signos"}),
W("Las columnas del templo están casi totalmente cubiertas con ellos. No tienes ni"
"idea de que son o que representan.\n"));

AddDetail(({"murales"}),
"Son frescos pintados en la pared oeste del templo. Acercate más para verlos.\n");

AddDetail(({"altar","altar"}),
W("El altar es una especie de mesa situada sobre una plataforma elevada que se "
"encuentra al sur del templo. Es en el donde Asthar realiza el rito sagrado que "
"permite encarnarse a los espiritus o cambiar la forma de un cuerpo. "));

AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
W("La isla Limbo es el lugar mágico de Simauria donde habitan los dioses. Gracias "
"a ellos, es en este lugar donde las almas de los seres se encarnan para poder "
"asi vivir en este mundo.\n"));

SetIntNoise("Oyes el ruido del las olas chocando contra los acantilados.\n");
SetIntSmell("Hmm.. el aire es fresco y limpio.\n");
SetLocate("isla Limbo");
SetIndoors(1);
SetIntBright(50);

AddExit("oeste",TEMPLO("templo03"));
AddExit("norte",TEMPLO("templo01"));
AddExit("este",TEMPLO("templo05"));
AddExit("sur",TEMPLO("altar"));
}
