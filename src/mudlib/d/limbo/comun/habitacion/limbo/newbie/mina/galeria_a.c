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
    SetIntShort("la galería de la mina");
    SetIntLong("La galería continúa avanzando por el interior de la mina. El ambiente es húmedo y hace frío debido "
        "principalmente al agua subterránea que gotea desde el techo.\nEn algunos lugares de las paredes aún se observan "
        "restos de vetas de mineral entre los pilares y traviesas de madera que soportan el techo de la galería.\n");
    AddDetail(({"techo"}),"En el techo de roca de la galería hay pequeñas grietas por las que se filtra el agua "
        "subterránea. Debido a las goteras que se forman por estas filtraciones, el suelo está mojado y resbaladizo.\n");
    AddDetail(({"vetas","paredes"}),"En algunos lugares de las paredes aún se observan restos de las vetas de mineral que "
        "contenía esta galería. Las vetas son capas de mineral o metal que se hallan entre las grietas de la roca que "
        "forma la montaña en la que está excavada esta mina.\n");
    AddDetail(({"pilares","traviesas"}),"Los pilares son gruesos troncos de madera colocados verticalmente junto a las "
        "paredes de la galería. Sobre ellos y colocadas de forma horizontal están las traviesas, gruesos listones de "
        "madera que a modo de vigas aguantan el peso del techo de la galería.\n");
    SetIntNoise("Oyes el eco de tus pasos y el goteo del agua.\n");
    SetIntSmell("Huele a tierra mojada.\n");
    SetLocate("mina de isla Limbo");
    SetIndoors(1);
    SetIntBright(0);
}
