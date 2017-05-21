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
    SetIntShort("un cruce entre galerías");
    SetIntLong("Has llegado a un cruce. En este punto coinciden varias de las galerías de este nivel de la mina. El "
        "ambiente es húmedo y hace frío debido principalmente al agua subterránea que gotea desde el techo.\n");
    AddDetail(({"cruce"}), QueryIntLong());
    AddDetail(({"agua","techo"}),"En el techo de roca de la galería hay pequeñas grietas por las que se filtra el "
        "agua subterránea. Debido a las goteras que se forman por estas filtraciones, el suelo está mojado y resbaladizo.\n");
    SetIntNoise("Oyes el eco de tus pasos y el goteo del agua.\n");
    SetIntSmell("Huele a tierra mojada.\n");
    SetLocate("mina de isla Limbo");
    SetIndoors(1);
    SetIntBright(0);
}
