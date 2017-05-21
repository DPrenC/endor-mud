/*
DESCRIPCION  : camino a la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/c_mina00.c
MODIFICACION : 27-08-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <moving.h>

inherit ROOM;

//los PNJ no entran/salen de la mina
int ir_se()
{
if (TP->QueryIsPlayer()) return TP->move(BOSQUE("c_mina01"),M_GO);
  return 1;
}

create()
{
    ::create();
    SetIntShort("el camino hacia la mina");
    SetIntLong("Te encuentras en un camino polvoriento que asciende hacia las montañas que se encuentran al noroeste de "
        "la isla.\nEl camino tiene una gran pendiente y asciende serpenteando entre rocas y matojos.\nEn medio de estas "
        "montañas se halla una vieja mina abandonada.\n");
    SetIntNoise("Oyes a los pájaros trinar y al viento aullar.\n");
    SetIntSmell("Huele a bosque.\n");
    SetLocate("isla Limbo");
    SetIndoors(0);
    AddExit("sudeste",SF(ir_se));
    AddExit("oeste",MINA("entrada"));
}
