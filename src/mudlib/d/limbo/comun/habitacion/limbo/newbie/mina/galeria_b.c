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
    SetIntShort("la galer�a de la mina");
    SetIntLong("La galer�a contin�a avanzando por el interior de la mina. El ambiente es h�medo y hace fr�o. El suelo de "
        "la galer�a est� inundado por unos dos palmos de un agua negra y fr�a que te cala hasta los huesos. Los pilares "
        "de madera que soportan el peso del techo de la galer�a no parecen muy de fiar.\n");
    AddDetail(({"agua"}),"El agua subterr�nea se filtra en el interior de la mina, produciendo incontables goteras en las "
        "galer�as. Este agua acaba llegando a los pozos de la mina y desliz�ndose por ellos hacia los niveles inferiores. "
        "Al ser en este nivel las paredes de roca casi maciza y no haber pozos a niveles inferiores, el agua se acumula "
        "aqu� hasta que poco a poco se filtra entre las rocas.\n");
    AddDetail(({"pilares","traviesas"}),"Los pilares son gruesos troncos de madera colocados verticalmente junto a las "
        "paredes de la galer�a. Sobre ellos, colocadas de forma horizontal, est�n las traviesas, gruesos listones de "
        "madera que a modo de vigas aguantan el peso del techo de la galer�a.\nAl estar la galer�a medio inundada por el "
        "agua subterr�nea, la madera est� medio podrida. No sabes si aguantar� el peso mucho m�s...\n");
    SetIntNoise("Oyes el eco de tus pasos y el goteo del agua.\n");
    SetIntSmell("Huele a tierra mojada.\n");
    SetLocate("mina de isla Limbo");
    SetIndoors(1);
    SetIntBright(0);
}
