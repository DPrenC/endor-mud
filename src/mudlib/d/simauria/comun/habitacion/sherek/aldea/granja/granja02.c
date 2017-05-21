/* Archivo        granja02.c
   Autor:         Yalin y Lug
   Fecha:         12/05/2006
   Descripción:   Calle de la granja de la aldea (proyecto)
*/

#include "path.h"
inherit SHERALD("granja/granja");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al norte asciende la calle, mientras que continúa su descenso "
        "hacia el sur. al este hay unos campos de labranza y al oeste puedes ver un establo. "
        "Al sureste ves un molino y el río.\n");
    SetIntNoise("Escuchas a los animales a tu alrededor y el sonido del agua del río entrando "
        "en el canal de un molino..\n");
    AddDetail(({"campos", "labranza", "campos de labranza"}), "Son las tierras pertenecientes "
        "a la granja donde se cultivan varios tipos de cereales.\n");
    AddDetail(({"cereales", "cereal"}), "Hay trigo, mijo, cebada y algún otro que no reconoces.\n");
    AddDetail(({"trigo", "mijo", "cebada"}), "Un simple tipo de cereal cultivado en el campo.\n");
    AddDetail(({"molino", "sureste"}), "Al mirar hacia abajo, al sureste, ves un molino de "
        "agua. Es una construcción de piedra cuadrangular dentro de la cual debe estar la "
        "maquinaria que anima el molino. A su lado se ve la esclusa y un puente que "
        "cruza el canal.\n");
    AddDetail(({"río", "rio"}), "Es el río Kandal que nace en las montañas de Sherek. Aquí "
        "todavía no alcanza el gran tamaño que tendrá en las llanuras, pero es "
        "muy caudaloso y sus aguas tienen una gran fuerza, útil para mover los "
        "molinos y batanes.\n");
    AddExit("norte", SHERALD("granja/granja01"));
    AddExit("sur", SHERALD("granja/granja03"));
    AddExit("este", SHERALD("campo/labranza03"));
    AddExit("oeste", SHERALD("granja/establo02"));
}
