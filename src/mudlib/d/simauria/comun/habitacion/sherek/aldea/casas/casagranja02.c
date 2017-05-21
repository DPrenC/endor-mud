/* Archivo:         casagranja02.c
   Autor:           Yalin y Lug
  Descripción:      Sótano de la casa de los administradores en la granja de la aldea de Sloch
  Fecha:            25/05/2006
*/

#include "path.h"
inherit SHERALD("ceroom");

create()
{
    ::create();
    SetIntShort("el sótano de la casa de los administradores en la granja de "
        "la aldea de Sloch.");
    SetIntLong("Te encuentras en el sótano de la casa. Aquí la temperatura "
        "es sensiblemente más fresca que en el resto de la vivienda, lo que "
        "lo hace un buen sitio para su utilización como bodega. Hay muy poca "
        "luz, tan sólo la que entra por la trampilla que une esta estancia "
        "con la planta baja a través de una empinada escalera que asciende "
        "en una de las esquinas. El resto de la habitación está ocupada por "
        "grandes toneles que contienen, posiblemente, diferentes tipos de "
        "binos y de bebidas espirituosas.\n");
    SetIntSmell("Huele a bebidas alcohólicas, en particular, a vino.\n");
    SetIntNoise("Solamente se escuchan, apagados, los pasos de las personas "
        "en la planta superior.\n");
    SetIntBright(20);
    AddDetail(({"suelo"}), "está hecho de grandes lajas de piedra. la "
        "suciedad lo cubre todo.\n");
    AddDetail(({"pared", "paredes"}), "Son paredes directamente escabadas en "
        "la dura roca que compone  este suelo. A lo largo de todas ellas se "
        "apilan muchas barricas conteniendo licores.\n");
    AddDetail(({"techo"}), "es un techo bajo compuesto de gruesos maderos "
        "apoyados en grandes vigas de madera.\n");
    AddDetail(({"viga", "vigas"}), "son grandes troncos que cruzan la "
        "estancia de lado a lado sobre los que se apoya  el suelo de la "
        "planta superior.\n");
    AddDetail(({"tonel","toneles","barril", "barriles", "barrica", "barricas"}),
        "Son grandes barriles de madera de roble dentro de los cuales se "
        "mete el vino y los demás licores que se generan en esta granja.\n");
    AddDetail(({"escaleras", "escalera"}), "es una escalera de madera muy "
        "empinada con unos peldaños muy desgastados por el tiempo y por el "
        "uso que ascienden a la parte superior.\n");
    AddExit("arriba", SHERALD("casas/casagranja01"));
}
