/*
DESCRIPCION  : pequenya cala en la costa oeste
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/cala00.c
MODIFICACION : 27-08-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create()
{
    ::create();
    SetIntShort("una pequeña cala en la costa oeste");
    SetIntLong("Has llegado a una pequeña cala encajonada entre acantilados de la abrupta costa oeste de la isla Limbo. "
        "No hay muchos lugares a lo largo de esta costa oeste en los que se pueda llegar al mar a pie. Observas como las "
        "olas chocan con violencia contra las rocas del acantilado que forman la entrada a esta cala.\n");
    AddDetail(({"acantilado","acantilados","rocas"}),"Los acantilados son altas paredes verticales que forman la costa "
        "oeste de la isla. La mayor parte de esta costa está formada por ellos y hacen casi imposible acceder a la isla "
        "desde el mar.\n");
    SetIntNoise("Oyes a las olas chocar en las rocas.\n");
    SetIntSmell("Huele a mar.\n");
    SetLocate("isla Limbo");
    SetIndoors(0);
    AddExit("sudeste",BOSQUE("senda"));
}
