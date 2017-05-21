/*
DESCRIPCION  : Senda al oeste del bosque
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/senda00.c
MODIFICACION : 27-08-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create()
{
    ::create();
    SetIntShort("una senda al oeste del bosque");
    SetIntLong("Te encuentras en un sendero que desciende desde el bosque hacia la abrupta costa oeste de la isla Limbo. "
        "Observas cómo hacia el noroeste el camino acaba en una pequeña y rocosa cala.\n");
    SetIntNoise("Oyes a las olas chocar a lo lejos.\n");
    SetIntSmell("Huele a mar.\n");
    SetLocate("isla Limbo");
    SetIndoors(0);
    AddExit("noroeste",BOSQUE("cala"));
    AddExit("este",BOSQUE("pradera05"));
}
