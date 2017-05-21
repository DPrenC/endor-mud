/*
DESCRIPCION  : cruce entre galerias (modelo)
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/cruce_1.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create()
{
    ::create();
    SetIntShort("un cruce entre galer�as");
    SetIntLong("Has llegado a un cruce. En este punto coinciden varias de las galer�as de este nivel de la mina. El "
        "ambiente es h�medo y hace fr�o debido principalmente al agua subterr�nea que gotea desde el techo.\n");
    AddDetail(({"cruce"}), QueryIntLong());
    AddDetail(({"agua","techo"}),"En el techo de roca de la galer�a hay peque�as grietas por las que se filtra el "
        "agua subterr�nea. Debido a las goteras que se forman por estas filtraciones, el suelo est� mojado y resbaladizo.\n");
    SetIntNoise("Oyes el eco de tus pasos y el goteo del agua.\n");
    SetIntSmell("Huele a tierra mojada.\n");
    SetLocate("mina de isla Limbo");
    SetIndoors(1);
    SetIntBright(0);
}
