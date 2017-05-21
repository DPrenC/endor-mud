/*
DESCRIPCION  : parte superior de un pozo en la mina (modelo)
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/pozo_a.c
MODIFICACION : 04-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create()
{
    ::create();
    SetIntShort("la parte superior de un pozo de la mina");
    SetIntLong("Te encuentras en una baja, húmeda y oscura galería de la mina. Las paredes están toscamente talladas en la "
        "roca y en algunos lugares de ellas asoman vetas de mineral. Pilares y traviesas de madera soportan el peso del "
        "techo de la galería.\nLa galería de este nivel acaba aquí, donde a tus pies se ha excavado un profundo pozo.\n"
        "Una escalera de madera permite bajar a niveles inferiores.\n");
    AddDetail(({"galeria"}), QueryIntLong());
    AddDetail(({"pozo"}),"A tus pies se abre un gran pozo en este extremo de la galería. Una escalera de madera permite "
        "bajar por él hasta, probablemente, un nivel inferior de la mina.\n");
    AddDetail(({"escalera"}),"Una larga escalera de madera está fijada firmemente a la pared del pozo. Permite bajar y "
        "subir por él.\n");
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
