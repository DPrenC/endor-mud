/*
DESCRIPCION  : cruce inundado entre galerias
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/cruce03.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create()
{
    ::create();
    SetIntShort("un cruce entre galerías");
    SetIntLong("Has llegado a un cruce. En este punto coinciden varias de las galerías de este nivel de la mina. Además, "
        "sobre tu cabeza se alza un agujero oscuro cuya altura no adivinas y que parece ser uno de los pozos de esta mina. "
        "Una escalera fijada en la pared del pozo permite ascender por él. El suelo de la galería está inundado por unos "
        "dos palmos de un agua negra y fría.\n");
    AddDetail(({"cruce"}), QueryIntLong());
    AddDetail(({"agua"}),"El agua subterránea se filtra en el interior de la mina, produciendo incontables goteras en las "
        "galerías. Este agua acaba llegando a los pozos de la mina y deslizándose por ellos hacia los niveles inferiores. "
        "Al ser en este nivel las paredes de roca casi maciza y no haber pozos a niveles inferiores, el agua se acumula "
        "aquí hasta que poco a poco se filtra entre las rocas.\n");
    AddDetail(({"escalera"}),"Una larga escalera de madera está fijada firmemente a la pared del pozo. Permite subir por "
        "él.\n");
    AddDetail(({"pozo"}),"Sobre este cruce de galerías no hay techo, sino un agujero oscuro en la roca. Es uno de los "
        "pozos excavados en esta mina para llegar de unos niveles a otros.\n");
    SetIntNoise("Oyes el eco de tus pasos y el goteo del agua.\n");
    SetIntSmell("Huele a tierra mojada.\n");
    SetLocate("mina de isla Limbo");
    SetIndoors(1);
    SetIntBright(0);
    AddExit("norte",MINA("pozo02"));
    AddExit("este",MINA("galeria06"));
    AddExit("arriba",MINA("fin00"));
    AddItem(PNJ("aranya"), REFRESH_DESTRUCT, 1);
}
