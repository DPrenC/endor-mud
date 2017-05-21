/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/campos/viñedo.c
Autor: Lug y Yalin
Fecha: 15/01/2007
Descripción: Base para los viñedos de la aldea.
****************************************************************************/

#include "path.h"
inherit SHERALD("abroom");

create()
{
    ::create();
    SetIntShort("un viñedo en la aldea de Sloch");
    SetIntLong("Estás sobre un terreno dedicado al cultivo de la vid. A tu "
        "alrededor ves plantadas en hileras las cepas que se extienden muy "
        "cerca del suelo apoyadas en un entramado de varas que las sostienen "
        "a una altura suficiente como para que resulte sencillo recoger el "
        "fruto en la hora de la vendimia.\n");
    SetIntSmell("Huele a vid.\n");
    SetIntNoise("Puedes oír el zumbido de los insectos, el canto de algún "
        "pájaro y el agua del río a lo lejos.\n");
    AddDetail(({"suelo"}), "Ves la tierra rojiza que ha sido arada para que "
        "las cepas crezcan adecuadamente.\n");
    AddDetail(({"cepa","cepas"}),"Son unas plantas trepadoras que, a finales "
        "del estío, más o menos, dan unos frutos llamados uvas que suelen "
        "utilizarse para hacer vino o para comerlos en los postres. No "
        "consigues saber de qué tipo de vid se trata.\n");
    AddDetail(({"vara","varas","entramado","entramado de varas"}),"son "
        "largas varas que cruzan el cultivo y sobre las que se apoyan las "
        "vides.\n");
    AddDetail(({"monte"}), "Es un bajo monte que limita el viñedo. Es tan "
        "espeso que impide el paso por él.\n");
}
