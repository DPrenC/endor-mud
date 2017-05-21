/*
DESCRIPCION  : parte baja inundada de un pozo en la mina (modelo)
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/pozo_c.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create()
{
    ::create();
    SetIntShort("la parte baja inundada de un pozo de la mina");
    SetIntLong("Sobre tu cabeza se alza un agujero oscuro cuya altura no adivinas. Estás en lo que parece ser la parte "
        "baja de uno de los pozos de esta mina. En la pared del pozo hay fijada una escalera que permite ascender por él. "
        "A partir de aquí parte también una galería de este nivel de la mina. El suelo está inundado por unos dos palmos de "
        "un agua negra y fría que te cala hasta los huesos.\n");
    AddDetail(({"pozo"}), QueryIntLong());
    AddDetail(({"escalera"}),"Una larga escalera de madera está fijada firmemente a la pared del pozo. Permite bajar y "
        "subir por él.\n");
    AddDetail(({"agua"}),"El agua subterránea se filtra en el interior de la mina, produciendo incontables goteras en las "
        "galerías. Este agua acaba llegando a los pozos de la mina y deslizándose por ellos hacia los niveles inferiores. "
        "Al ser en este nivel las paredes de roca casi maciza y no haber pozos a niveles inferiores, el agua se acumula "
        "aquí hasta que poco a poco se filtra entre las rocas.\n");
    SetIntNoise("Oyes el eco de tus pasos y el goteo del agua.\n");
    SetIntSmell("Huele a tierra mojada.\n");
    SetLocate("mina de isla Limbo");
    SetIndoors(1);
    SetIntBright(0);
}
