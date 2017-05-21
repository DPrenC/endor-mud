/*=============================================================*
 |           << GOLDHAI.Magia [w] Woo@simauria >>              |
 *=============================================================*
 |              Creacion............. 20-10-99                 |
 |              Ultima Modificacion...20-10-99                 |
 |                                                             |
 *=============================================================*/

#include <properties.h>
inherit "/obj/pergamino";


create()
{
    ::create();
    SetShort("el pergamino de miedo paralizante");
    SetLong("Se trata de un pergamino bastante deteriorado. Te fijas un poco "
        "más y puedes observar que tiene escritas varias frases con una "
        "letra clara y bonita.\nEn el encabezado lees 'hechizo de miedo "
        "paralizante'.\nQuizás si lo intentases hasta podrías hacerlo o "
        "incluso memorizarlo.\n");
    SetIds(({"pergamino","miedo paralizante","hoja","papel"}));
    SetValue(30000);
    SetWeight(100);
    Set(P_GENDER,GENERO_MASCULINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    SetCanMemorize(1);
    SetCanCast(1);
    SetMaxCast(1);
    SetScrollID("miedo paralizante");
    SetDestructMsg("El pergamino comienza a arder en tus manos y se "
        "convierte en ceniza.\n");
}


