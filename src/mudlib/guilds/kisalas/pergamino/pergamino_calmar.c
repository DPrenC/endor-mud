/*=============================================================*
 |           << GOLDHAI.Magia [w] Woo@simauria >>              |
 *=============================================================*
 |              Creacion............. 08-12-99                 |
 |              Ultima Modificacion...08-12-99                 |
 |                                                             |
 *=============================================================*/

#include <properties.h>
inherit "/obj/pergamino";

create()
{
    ::create();
    SetShort("el pergamino de calmar ambiente");
    SetLong("Se trata de un pergamino bastante deteriorado. Te fijas un poco "
        "más y puedes observar que tiene escritas varias frases con una "
        "letra clara y bonita.\nEn el encabezado lees 'hechizo calmar "
        "ambiente'.\nQuizás si lo intentases hasta podrías hacerlo o incluso "
        "memorizarlo.\n");
    SetIds(({"pergamino","calmar","hoja","papel"}));
    SetValue(20000);
    SetWeight(100);
    Set(P_GENDER,GENERO_MASCULINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    SetCanMemorize(1);
    SetCanCast(1);
    SetMaxCast(1);
    SetScrollID("calmar ambiente");
    SetDestructMsg("El pergamino comienza a arder en tus manos y se "
        "convierte en ceniza.\n");
}


