/*=============================================================*
 |            << GOLDHAI.Gremio [w] Woo@simauria >>            |
 *=============================================================*
 |               Creacion.............. 02-12-99               |
 |               Ultima Modificacion... 02-12-99               |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <guild.h>
#include <properties.h>


inherit NPC;

create()
{
    ::create();
    SetStandard("Danna","elfo",([GC_KISALAS:40]),GENERO_FEMENINO);
    SetIds(({"danna","Danna","kisala","amazona","elfa","hechicera","hechicera kisala",
             "herrera"}));
    SetShort("Danna, la herrera");
    SetLong("Danna es una Kisala, responsable de la armería del Gremio. "
            "Es una elfa de esbelta figura, en parte debido a su raza y en "
            "parte a la preparación de las Kisalas. Su cara muestra "
            "amabilidad, mas sus ojos no dejan de intrigarte.\n");

    SetAlign(100);
    SetWhimpy(20);

    InitChats(3,({
              "Danna coge un martillo y se pone a golpear un trozo de metal.\n",
              "Danna te dice: ¿Quieres algo?.\n",
              "La herrera baña una barra de metal candente en agua.\n"}));
}

