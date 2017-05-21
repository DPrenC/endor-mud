/*
DESCRIPCION  : camino a la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/c_mina01.c
MODIFICACION : 27-08-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <moving.h>

inherit ROOM;

//los PNJ no entran/salen de la mina
int ir_no()
{
if (TP->QueryIsPlayer()) return TP->move(BOSQUE("c_mina00"),M_GO);
  return 1;
}

create()
{
    ::create();
    SetIntShort("el camino hacia la mina");
    SetIntLong("El camino en el que te hallas asciende hasta las montañas. El camino serpentea a medida que asciende "
        "hacia el noroeste aumentando poco a poco su pendiente.\nAl sur de aquí observas una zona de bosques y praderas.\n");
    SetIntNoise("Oyes a los pájaros trinar y al viento aullar.\n");
    SetIntSmell("Huele a bosque.\n");
    SetLocate("isla Limbo");
    SetIndoors(0);
    AddExit("noroeste",SF(ir_no));
    AddExit("sur",BOSQUE("pradera11"));
}
