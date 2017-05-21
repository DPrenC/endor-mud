
#include "./path.h"
#include <magia.h>

inherit GROOM;

create()
{
::create();
SetIntShort("la bodega del barco");
SetIntLong(
"La bodega del barco esta inundada y el agua te cubre la mitad casi hasta la "
"cintura. Restos de cajas y barriles flotan chocando entre si. El casco "
"del barco cruje lastimeramente cada vez que una ola lo embiste. La rampa "
"de acceso a la cubierta está dañada pero aun permite salir de aquí.\n");

AddDetail(({"caja","cajas","barril","barriles"}),
"Cajas y barriles flotan en la bodega inundada. Rebuscas en ellos pero no "
"encuentras nada interesante.\n");

AddExit("arriba",ACANTILADO("barco"));

SetTPort(TPORT_NO);
ForbidAllMagic();
SetLocate("acantilado del suroeste de Goldhai");
}