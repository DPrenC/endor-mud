/* Archivo        callejuela01.c
   Autor:         Yalin y Lug
   Fecha:         05/05/2006
   Descripci�n:   Callejuela que conecta la plaza de la aldea con el lavadero (proyecto)
*/


#include "path.h"
inherit SHERALD("abroom");

create ()
{
    ::create();
    SetIntShort("una callejuela de la aldea de Sloch");
    SetIntLong("Est�s en una estrecha callejuela de guijarros que conecta la plaza de la aldea "
    "con el camino que baja al lavadero que hay en la orilla del r�o. Al norte y al sur "
    "puedes ver ambas caba�as. Hacia el este prosigue la calle y hacia el suroeste desciende un "
    "camino hacia el r�o.\n");
    SetIntNoise("Oyes el parloteo de los aldeanos en los alrededores.\n");
    SetIntSmell("Huele a bosta de vaca.\n");
    AddDetail(({"suelo", "camino"}), "El suelo de esta calle se compone de "
        "peque�os guijarros incrustados en la tierra endurecida.\n");
    AddDetail(({"sur", "norte", "caba��a"}), "Puedes ver una pobre caba�a de "
    "troncos mal aserrados y peor unidos entre s�. Lo m�s probable es que "
    "ah� vivan gentes con muy pocos recursos.\n");
    AddExit("este", SHERALD("calles/callejuela00"));
    AddExit("suroeste", SHERALD("calles/caminorio00"));
    AddExit("oeste", SHERALD("casas/bodega05"));
    AddExit("norte", SHERALD("casas/cabanya00"));
    AddExit("sur", SHERALD("casas/cabanya01"));
    AddItem(PNJ("sherek/aldea/guardian"), REFRESH_DESTRUCT,1);
}
