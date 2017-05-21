/***************************************************************************************
 ARCHIVO:	jefe.c
 AUTOR:		[k] Korsario
 FECHA:		28-02-1998
 COMENTARIOS:	Casa del Jefe de Flenton
 ***************************************************************************************/

#include "path.h"

inherit ROOM;

create(){
  ::create();

  SetIndoors(1);
  SetIntBright(80);
  SetLocate("flenton");
  SetIntNoise("Escuchas una dulce melodía.\n");
  SetIntSmell("Huele a tabaco.\n");
  SetIntShort("la casa del jefe");
  SetIntLong("Esta es la casa del Jefe del poblado. Es una estancia amplia "
  	"y bonita. Las paredes estan decoradas con los objetos mas diversos: "
  	"pieles, escudos, armas, cacerolas... todos muy brillantes y bonitos. "
  	"Al fondo hay un sillon rojo y grande, donde se suele sentar el jefe. "
  	"Encima hay un tapiz con el emblema del poblado. A ambos lados hay "
  	"sillas donde poder sentarse.\n");

  AddDetail(({"pared"}),"Las paredes estan repletas de los objetos mas "
  	"diversos, hay desde pieles y escudos, hasta cacerolas y piedras.\n");
  AddDetail(({"piedras","piedras de colores"}),"Son piedras de muy diversos "
  	"colores. Son muy bonitas.\n");
  AddDetail(({"silla"}),"Es una silla pequeña de madera tapizada en rojo.\n");
  AddDetail(({"pieles"}),"Son pieles curtidas de animales. Las hay de diversos "
  	"tamaños.\n");
  AddDetail(({"cacerola"}),"Es una cacerola de tamaño medio y muy brillante. "
  	"Esta nueva.\n");
  AddDetail(({"armas"}),"Hay armas muy diversas, desde un arco, hasta un hacha "
  	"de guerra. Todas parecen sin usar.\n");
  AddDetail(({"arco"}),"Es un arco de tamaño medio. Esta en perfecto estado.\n");
  AddDetail(({"hacha"}),"Es un hacha de combate. Esta en perfecto estado.\n");
  AddDetail(({"escudo"}),"Es un escudo de metal. Esta algo abollado.\n");
  AddDetail(({"sillon","sillón"}),"Es un gran sillon de color rojo. Parece muy "
  	"confortable. En el se suele sentar el jefe.\n");
  AddDetail(({"tapiz","emblema"}),"Es un tapiz muy bonito que representa a un "
  	"gran árbol. En el troco del árbol hay incrustada una piedra verde que "
  	"parece brillar. Es el emblema de Flenton.\n");
  AddDetail(({"piedra verde"}),"En el tronco del árbol del tapiz hay incustrada "
  	"una piedra verde.\n");

  AddExit("este",FLENHAB+"calles/plaza_00");
  AddItem(FLENPNJ+"poblado/jefe",REFRESH_DESTRUCT);
}
