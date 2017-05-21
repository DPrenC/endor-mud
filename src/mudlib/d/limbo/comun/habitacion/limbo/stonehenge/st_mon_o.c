/*
DESCRIPCION  : Oeste del circulo interior de Stonehenge
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/st_mon_o.c
MODIFICACION : 25-01-98 [angor] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;


create() {
  ::create();
  SetIntShort("el Oeste del círculo interior de Stonehenge.");
  SetIntLong("Te encuentras en el circulo interior de Stonehenge. Frente a ti se abre un area "
"circular que forma el corazon de Stonehenge, y al este, en su centro, se alza "
"imponente un inmenso monolito rectangular de basalto negro que levita a pocos "
"metros del suelo. Parece como si la magia de este lugar emanase de el... Un arco "
"en el muro interior, permite llegar llegar a la zona mas externa de Stonehenge\n");

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
 "Es un inmenso bloque de basalto negro que, inexplicablemente, levita a pocos "
  "metros del suelo. Sus caras son tan planas y lisas como espejos, y sus aristas "
  "son perfectamente rectas. Sus medidas son 1 metro de ancho, 4 de largo y 9 de "
  "alto, los cuadrados de los tres primeros numeros primos. Su perfecta y fria "
  "belleza es sobrecogedora. Sin duda es obra de seres poderosos, y tal vez ni "
  "siquiera pertenezca a este mundo. Supones que, de alguna manera, es el origen "
  "de la magia que hay en este lugar.\n");

SetIntNoise("Solo se oye a lo lejos el rumor de la vida en el bosque.\n");
SetIntSmell("El aire es limpio y fresco.\n");
SetLocate("Stonehenge");
SetIndoors(0);

AddExit("nordeste",STONE("st_mon_n"));
AddExit("oeste",STONE("st_fuego"));
AddExit("sudeste",STONE("st_mon_s"));
AddExit("este",STONE("monolito"));
}
