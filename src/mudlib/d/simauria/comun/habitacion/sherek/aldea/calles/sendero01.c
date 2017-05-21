/* Archivo: /d/simauria/comun/habitacion/abadia/aldea/sendero01.c
* descripci�n: sendero del camino a la aldea
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
    "aldea.\nHacia el noroeste vuelves al camino de Nandor a la abad�a de "
    "Sherek, mientras que al sudeste se halla la aldea.\n");
    SetIntSmell("Huele a aldea t�pica: campos y vacas...\n");
    SetIntNoise("S�lo el balido de ovejas y mugidos de vaca en lontananza.\n");
    AddDetail(({"campo","campos","cultivo","cultivos","sembrado","sembrados"}), "Grandes "
        "extensiones de sembrados y tierras de cultivo por todas partes.");
    AddExit("noroeste", SHERALD("calles/sendero00"));
    AddExit("sudeste", SHERALD("calles/sendero02"));
}
