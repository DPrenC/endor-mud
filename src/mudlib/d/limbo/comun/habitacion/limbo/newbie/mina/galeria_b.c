/*
DESCRIPCION  : galeria tipo de la mina (nivel -1)
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/galeria_b.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create()
{
    ::create();
    SetIntShort("la galería de la mina");
    SetIntLong("La galería continúa avanzando por el interior de la mina. El ambiente es húmedo y hace frío. El suelo de "
        "la galería está inundado por unos dos palmos de un agua negra y fría que te cala hasta los huesos. Los pilares "
        "de madera que soportan el peso del techo de la galería no parecen muy de fiar.\n");
    AddDetail(({"agua"}),"El agua subterránea se filtra en el interior de la mina, produciendo incontables goteras en las "
        "galerías. Este agua acaba llegando a los pozos de la mina y deslizándose por ellos hacia los niveles inferiores. "
        "Al ser en este nivel las paredes de roca casi maciza y no haber pozos a niveles inferiores, el agua se acumula "
        "aquí hasta que poco a poco se filtra entre las rocas.\n");
    AddDetail(({"pilares","traviesas"}),"Los pilares son gruesos troncos de madera colocados verticalmente junto a las "
        "paredes de la galería. Sobre ellos, colocadas de forma horizontal, están las traviesas, gruesos listones de "
        "madera que a modo de vigas aguantan el peso del techo de la galería.\nAl estar la galería medio inundada por el "
        "agua subterránea, la madera está medio podrida. No sabes si aguantará el peso mucho más...\n");
    SetIntNoise("Oyes el eco de tus pasos y el goteo del agua.\n");
    SetIntSmell("Huele a tierra mojada.\n");
    SetLocate("mina de isla Limbo");
    SetIndoors(1);
    SetIntBright(0);
}
