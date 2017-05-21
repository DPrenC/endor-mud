/* Archivo        granja00.c
   Autor:         Yalin y Lug
   Fecha:         12/05/2006
   Descripción:   Calle de la granja de la aldea (proyecto)
*/

#include "path.h"
inherit SHERALD("abroom");

create()
{
    ::create();
    SetIntShort("una calle dentro de la granja de la aldea de Sloch");
    SetIntLong("Estás en una especie de calle que desciende de norte a sur y "
        "que recorre el interior de la granja comunicando entre sí todas sus "
        "estancias. Es bastante ancha y despejada para permitir el trasiego "
        "de hombres, animales y carretas que hay en este lugar.\n");
    SetIntNoise("Escuchas a los animales a tu alrededor y el trasiego de la "
        "gente mientras trabaja en las cercanías.\n");
    SetIntSmell("Huele a animales y a campo... lo típico de una granja.\n");
    AddDetail(({"suelo"}), "es de gravilla tan apisonada que parece arena. "
        "En las orillas ves crecer hierbas; posiblemente por ser las zonas "
        "menos pisadas por animales y personas.\n");
    AddDetail(({"hierba", "hierbas"}), "Son hierbas vulgares que crecen a "
        "ambos lados del camino.\n");
    AddDetail(({"establo","establos","oeste"}),"se trata de un edificio de "
        "madera bastante amplio y ligeramente alzado sobre el nivel del "
        "suelo, donde se guarda el ganado al atardecer. Es de mejor "
        "construcción que muchas cabañas de los propios aldeanos.\n");
}
