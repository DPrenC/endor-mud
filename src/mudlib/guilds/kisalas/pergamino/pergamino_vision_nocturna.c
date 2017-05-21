/*=============================================================*
 |           << GOLDHAI.Magia [w] Woo@simauria >>              |
 *=============================================================*
 |              Creacion............. 29-05-99                 |
 |              Ultima Modificacion...29-05-99                 |
 |                                                             |
 *=============================================================*/

#include <properties.h>
inherit "/obj/pergamino";


create()
{
    ::create();
    SetShort("el pergamino de visión nocturna");
    SetLong("Se trata de un pergamino bastante deteriorado. Te fijas un poco "
        "más y puedes observar que tiene escritas varias frases con una "
        "letra clara y bonita.\nEn el encabezado lees 'hechizo de vision "
        "nocturna'.\nQuizás si lo intentases hasta podrías hacerlo o incluso "
        "memorizarlo.\n");
    SetIds(({"pergamino","vision nocturna","hoja","papel"}));
    SetValue(10000);
    SetWeight(100);
    Set(P_GENDER,GENERO_MASCULINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    SetCanMemorize(1);
    SetCanCast(1);
    SetMaxCast(1);
    SetScrollID("vision nocturna");
    SetDestructMsg("El pergamino comienza a arder en tus manos y se "
        "convierte en ceniza.\n");
}


