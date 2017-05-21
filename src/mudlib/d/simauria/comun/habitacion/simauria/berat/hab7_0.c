/*
DESCRIPCION  : Dentro de ua casa
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/hab7_0.c
MODIFICACION : 05-11-99 [Jorus@Simauria] Creación.
[Maler]
--------------------------------------------------------------------------------
*/
#include "path.h"

inherit SIM_ROOM;

create() {
::create();
SetLocate("berat");
SetIntShort("el sótano");
SetIntLong(W("Estás en el sótano de una casa bastante grande, apenas está decorado "
"e iluminado. Está lleno de trastos inútiles, puedes ver cajas por todos lados "
"quizás si mirases podrías encontrar algo de tu interés......\n"));


SetIndoors(1);
SetIntNoise("Lo único que escuchas es el distante rumor del mar.\n");
SetIntSmell("Como cabe esperar, todo está impregnado con un olor a mar.\n");
SetIntBright(10);

AddDetail(({"caja","cajas"}),W("Por todas partes ves cajas de madera cerradas con clavos "
"parece que los dueños aprecian de verdad lo que llevan ahí dentro.\n"));

AddExit("arriba","./hab7_1");

}