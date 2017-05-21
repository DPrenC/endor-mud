/* Archivo        callejuela01.c
   Autor:         Yalin y Lug
   Fecha:         05/05/2006
   Descripción:   Callejuela que conecta la plaza de la aldea con el lavadero (proyecto)
*/


#include "path.h"
inherit SHERALD("abroom");

create ()
{
    ::create();
    SetIntShort("una callejuela de la aldea de Sloch");
    SetIntLong("Estás en una estrecha callejuela de guijarros que conecta la plaza de la aldea "
    "con el camino que baja al lavadero que hay en la orilla del río. Al norte y al sur "
    "puedes ver ambas cabañas. Hacia el este prosigue la calle y hacia el suroeste desciende un "
    "camino hacia el río.\n");
    SetIntNoise("Oyes el parloteo de los aldeanos en los alrededores.\n");
    SetIntSmell("Huele a bosta de vaca.\n");
    AddDetail(({"suelo", "camino"}), "El suelo de esta calle se compone de "
        "pequeños guijarros incrustados en la tierra endurecida.\n");
    AddDetail(({"sur", "norte", "cabañña"}), "Puedes ver una pobre cabaña de "
    "troncos mal aserrados y peor unidos entre sí. Lo más probable es que "
    "ahí vivan gentes con muy pocos recursos.\n");
    AddExit("este", SHERALD("calles/callejuela00"));
    AddExit("suroeste", SHERALD("calles/caminorio00"));
    AddExit("oeste", SHERALD("casas/bodega05"));
    AddExit("norte", SHERALD("casas/cabanya00"));
    AddExit("sur", SHERALD("casas/cabanya01"));
    AddItem(PNJ("sherek/aldea/guardian"), REFRESH_DESTRUCT,1);
}
