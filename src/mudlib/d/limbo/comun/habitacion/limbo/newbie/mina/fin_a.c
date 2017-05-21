/*
DESCRIPCION  : final de una galeria de la mina (modelo)
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/fin_a.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create()
{
    ::create();
    SetIntShort("el fin de una galería de la mina");
    SetIntLong("La galería acaba aquí. Por alguna razón los mineros decidieron dejar de excavar en esta galería, "
        "posiblemente al no encontrar la veta que buscaban o porque otra galería resultaba más productiva. Hay un montón de "
        "piedras de distintos tamaños en el lugar donde se dejó de excavar. El suelo está mojado por el agua subterránea "
        "que gotea desde el techo.\n");
    AddDetail(({"galeria","final"}), QueryIntLong());
    AddDetail(({"piedra","piedras"}),"Son las piedras que se desprenden al excavar la galería y que han de llevarse al "
        "lavadero que hay en el exterior de la mina para ver si contienen algún mineral de valor. Como se dejó de excavar "
        "esta galería, nadie se molestó en llevarlas al lavadero.\n");
    SetIntNoise("Oyes el eco de tus pasos y el goteo del agua.\n");
    SetIntSmell("Huele a tierra mojada.\n");
    SetLocate("mina de isla Limbo");
    SetIndoors(1);
    SetIntBright(0);
}
