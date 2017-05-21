/*
DESCRIPCION  : Dentro de ua casa
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/hab7_0.c
MODIFICACION : 05-11-99 [Jorus@Simauria] Creaci�n.
[Maler]
--------------------------------------------------------------------------------
*/
#include "path.h"

inherit SIM_ROOM;

create() {
::create();
SetLocate("berat");
SetIntShort("el s�tano");
SetIntLong(W("Est�s en el s�tano de una casa bastante grande, apenas est� decorado "
"e iluminado. Est� lleno de trastos in�tiles, puedes ver cajas por todos lados "
"quiz�s si mirases podr�as encontrar algo de tu inter�s......\n"));


SetIndoors(1);
SetIntNoise("Lo �nico que escuchas es el distante rumor del mar.\n");
SetIntSmell("Como cabe esperar, todo est� impregnado con un olor a mar.\n");
SetIntBright(10);

AddDetail(({"caja","cajas"}),W("Por todas partes ves cajas de madera cerradas con clavos "
"parece que los due�os aprecian de verdad lo que llevan ah� dentro.\n"));

AddExit("arriba","./hab7_1");

}