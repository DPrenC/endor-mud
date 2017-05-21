/*
DESCRIPCION  : Monolito en el centro de Stonehenge
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/monolito.c
MODIFICACION : 25-01-98 [Angor@Simauria] Creacion.
               19-10-98 [Angor@Siamuria] Retoques
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;


create() {
  ::create();
  SetIntShort("el monolito en el centro de Stonehenge");
  SetIntLong(
    "Te encuentras en el centro mismo de Stonehenge a los pies del monolito. Este "
    "inmenso bloque rectangular de basalto negro levita a un medio metro del suelo y "
    "parece ser la fuente del poder presente en este lugar. Te das cuenta de que "
    "un misterioso y angustioso silencio lo envuelve todo y solo eres capaz de oir tu "
    "propia respiracion.\n");

 AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
  "La isla Limbo es el lugar magico de Simauria donde habitan los dioses. "
  "Gracias a ellos, es en este lugar donde las almas de los seres se "
  "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

 AddDetail(({"Stonehenge","stonehenge","monumento"}),
  "Stonehenge es un monumento de piedra que se encuentra sobre una loma "
  "al oeste de la isla Limbo. El poder de los dioses hace que este lugar "
  "este conectado, de forma inexplicable, a otros muchos lugares a lo "
  "largo y ancho de Simauria.\n");

 AddDetail(({"monolito","gran monolito"}),
  "Es un inmenso bloque de basalto negro que, inexplicablemente, levita a un medio "
  "metro del suelo. Sus caras son tan planas y lisas como espejos, y sus aristas "
  "son perfectamente rectas. Sus medidas son 1 metro de ancho, 4 de largo y 9 de "
  "alto, los cuadrados de los tres primeros numeros primos. Su perfecta y fria "
  "belleza es sobrecogedora. Sin duda es obra de seres poderosos, y tal vez ni "
  "siquiera pertenezca a este mundo. Supones que, de alguna manera, es el origen "
  "de la magia que hay en este lugar.\n");

SetIntNoise("Solo tu respiracion rompe el misterioso silencio.\n");
SetIntSmell("El aire es limpio y fresco.\n");
SetLocate("Stonehenge");
SetIndoors(0);

AddExit("este",STONE("st_mon_e"));
AddExit("sur",STONE("st_mon_s"));
AddExit("oeste",STONE("st_mon_o"));
AddExit("norte",STONE("st_mon_n"));
}
