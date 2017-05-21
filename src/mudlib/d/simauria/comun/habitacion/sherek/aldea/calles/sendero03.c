/* Archivo: /d/simauria/comun/habitacion/abadia/aldea/sendero03.c
* descripción: sendero del camino a la aldea
* autor Lug y Yalin
*/
#include "path.h"
inherit SHERALD("abroom");

create()
{
    ::create();
    SetIntShort("el sendero hacia la aldea de Sloch");
    SetIntLong("Te encuentras en el sendero que une el camino hacia Nandor "
    "con la aldea de Sloch.\nSe extiende entre los campos de cultivo de la "
    "aldea.\nHacia el noroeste vuelves al camino de Nandor a la abadía de "
    "Sherek, mientras que hacia el este entras en la aldea.\n");
    SetIntSmell("Huele a aldea típica: campos y vacas...\n");
    SetIntNoise("Sólo el balido de ovejas y mugidos de vaca en lontananza.\n");
    AddDetail(({"campo","campos","cultivo","cultivos","sembrado","sembrados"}), "Grandes "
        "extensiones de sembrados y tierras de cultivo por todas partes.");
    AddExit("noroeste", SHERALD("calles/sendero02"));
    AddExit("este", SHERALD("calles/calle00"));
}
