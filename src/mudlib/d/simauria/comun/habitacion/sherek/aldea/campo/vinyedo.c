/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/campos/vi�edo.c
Autor: Lug y Yalin
Fecha: 15/01/2007
Descripci�n: Base para los vi�edos de la aldea.
****************************************************************************/

#include "path.h"
inherit SHERALD("abroom");

create()
{
    ::create();
    SetIntShort("un vi�edo en la aldea de Sloch");
    SetIntLong("Est�s sobre un terreno dedicado al cultivo de la vid. A tu "
        "alrededor ves plantadas en hileras las cepas que se extienden muy "
        "cerca del suelo apoyadas en un entramado de varas que las sostienen "
        "a una altura suficiente como para que resulte sencillo recoger el "
        "fruto en la hora de la vendimia.\n");
    SetIntSmell("Huele a vid.\n");
    SetIntNoise("Puedes o�r el zumbido de los insectos, el canto de alg�n "
        "p�jaro y el agua del r�o a lo lejos.\n");
    AddDetail(({"suelo"}), "Ves la tierra rojiza que ha sido arada para que "
        "las cepas crezcan adecuadamente.\n");
    AddDetail(({"cepa","cepas"}),"Son unas plantas trepadoras que, a finales "
        "del est�o, m�s o menos, dan unos frutos llamados uvas que suelen "
        "utilizarse para hacer vino o para comerlos en los postres. No "
        "consigues saber de qu� tipo de vid se trata.\n");
    AddDetail(({"vara","varas","entramado","entramado de varas"}),"son "
        "largas varas que cruzan el cultivo y sobre las que se apoyan las "
        "vides.\n");
    AddDetail(({"monte"}), "Es un bajo monte que limita el vi�edo. Es tan "
        "espeso que impide el paso por �l.\n");
}
