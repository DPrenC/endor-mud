/*
DESCRIPCION  : Portal 'tipo' vacio utilizado en Stonehenge.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/portal_vacio.c
MODIFICACION : 24-01-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

public string muro; //interior o exterior

create() {
  ::create();
  SetPreIntShort("junto a");
  SetIntShort("un Portal no utilizado");
  SetIntLong(
"Te encuentras en el corredor interior entre los dos anillos de piedra de "
"Stonehenge junto a un portal en el muro "+muro+". Ni en la losa de piedra que "
"hay en el suelo junto al portal, ni en el propio portal hay ninguna indicacion "
"de a que raza pertenece. Piensas que lo mas probable es que se trate del portal "
"de una raza ya extinta o aun no nacida.\n");

 AddDetail(({"acantilado","acantilados"}),
  "Mirando al oeste a traves de los arcos de piedra de Stonehenge, observas "
  "como la loma acaba bruscamente en el acantilado que forma la costa oeste "
  "de la isla Limbo. Aunque desde aqui no se ve el acantilado directamente, "
  "oyes el ruido de las olas chocando furiosamente contra el.\n");

 AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
  "La isla Limbo es el lugar magico de Simauria donde habitan los dioses. "
  "Gracias a ellos, es en este lugar donde las almas de los seres se "
  "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

 AddDetail(({"Stonehenge","stonehenge","monumento"}),
  "Stonehenge es un monumento de piedra que se encuentra sobre una loma "
  "al oeste de la isla Limbo. El poder de los dioses hace que este lugar "
  "este conectado, de forma inexplicable, a otros muchos lugares a lo "
  "largo y ancho de Simauria.\n");

 AddDetail(({"portal","arco","arco de piedra"}),
  "Frente a ti tienes uno de los portales de Stonehenge. Esta constituido por tres "
  "inmensos bloques de piedra, dos colocados en vertical y el tercero situado "
  "horizontalmente sobre los anteriores. Cuando miras a traves de el, sucede algo "
  "extranyo: el paisaje que ves de la isla tiembla como cuando se mira una imagen "
  "reflejada sobre una superficie de agua. Tienes la sensacion de que este portal "
  "debe ser una especie de 'puerta' magica a alguna otra parte...\n");

SetIntNoise("Se oyen el ruido de las olas en los acantilados del oeste de la isla.\n");
SetIntSmell("El aire es limpio y fresco.\n");
SetLocate("Stonehenge");
SetIndoors(0);
}
