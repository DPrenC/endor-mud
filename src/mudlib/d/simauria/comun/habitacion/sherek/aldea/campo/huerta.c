/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/campo/huerta.c
Autor: Lug y Yalin
Fecha: 15/01/2007
Descripción: Base para los sembrados de hortalizas de la aldea.
****************************************************************************/


#include "path.h"
inherit SHERALD("abroom");

create()
{
    ::create();
    SetIntShort("la huerta de la aldea de Sloch");
    SetIntLong("Te encuentras en un campo roturado en la granja de la aldea "
        "de Sloch. En esta zona se cultivan legumbres y verduras para el "
        "consumo humano que, cuando estén listas, serán llevadas a la abadía "
        "de Sherek.\n");
    SetIntNoise("Oyes el chapoteo de la corriente en el río.\n");
    SetIntSmell("Huele a tierra removida y a humedad.\n");
    AddDetail(({"suelo"}), "La tierra está removida, puesto que han sido "
        "plantados en ella verduras, legumbres y otras plantas para el "
        "consumo humano.\n");
    AddDetail(({"legumbres","vegetales","verduras"}),"Están cultivadas en "
        "las tierras que te rodean. Cuando estén listas para su consumo, "
        "serán llevadas hasta la abadía de Sherek.\n");
}
