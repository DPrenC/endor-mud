/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/campo/huerta.c
Autor: Lug y Yalin
Fecha: 15/01/2007
Descripci�n: Base para los sembrados de hortalizas de la aldea.
****************************************************************************/


#include "path.h"
inherit SHERALD("abroom");

create()
{
    ::create();
    SetIntShort("la huerta de la aldea de Sloch");
    SetIntLong("Te encuentras en un campo roturado en la granja de la aldea "
        "de Sloch. En esta zona se cultivan legumbres y verduras para el "
        "consumo humano que, cuando est�n listas, ser�n llevadas a la abad�a "
        "de Sherek.\n");
    SetIntNoise("Oyes el chapoteo de la corriente en el r�o.\n");
    SetIntSmell("Huele a tierra removida y a humedad.\n");
    AddDetail(({"suelo"}), "La tierra est� removida, puesto que han sido "
        "plantados en ella verduras, legumbres y otras plantas para el "
        "consumo humano.\n");
    AddDetail(({"legumbres","vegetales","verduras"}),"Est�n cultivadas en "
        "las tierras que te rodean. Cuando est�n listas para su consumo, "
        "ser�n llevadas hasta la abad�a de Sherek.\n");
}
