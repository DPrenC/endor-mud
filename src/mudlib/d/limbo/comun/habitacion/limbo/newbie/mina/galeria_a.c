/*
DESCRIPCION  : galeria tipo de la mina (nivel 0)
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/galeria.c
MODIFICACION : 04-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create()
{
    ::create();
    SetIntShort("la galer�a de la mina");
    SetIntLong("La galer�a contin�a avanzando por el interior de la mina. El ambiente es h�medo y hace fr�o debido "
        "principalmente al agua subterr�nea que gotea desde el techo.\nEn algunos lugares de las paredes a�n se observan "
        "restos de vetas de mineral entre los pilares y traviesas de madera que soportan el techo de la galer�a.\n");
    AddDetail(({"techo"}),"En el techo de roca de la galer�a hay peque�as grietas por las que se filtra el agua "
        "subterr�nea. Debido a las goteras que se forman por estas filtraciones, el suelo est� mojado y resbaladizo.\n");
    AddDetail(({"vetas","paredes"}),"En algunos lugares de las paredes a�n se observan restos de las vetas de mineral que "
        "conten�a esta galer�a. Las vetas son capas de mineral o metal que se hallan entre las grietas de la roca que "
        "forma la monta�a en la que est� excavada esta mina.\n");
    AddDetail(({"pilares","traviesas"}),"Los pilares son gruesos troncos de madera colocados verticalmente junto a las "
        "paredes de la galer�a. Sobre ellos y colocadas de forma horizontal est�n las traviesas, gruesos listones de "
        "madera que a modo de vigas aguantan el peso del techo de la galer�a.\n");
    SetIntNoise("Oyes el eco de tus pasos y el goteo del agua.\n");
    SetIntSmell("Huele a tierra mojada.\n");
    SetLocate("mina de isla Limbo");
    SetIndoors(1);
    SetIntBright(0);
}
