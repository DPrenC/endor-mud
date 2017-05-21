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
    SetShort("el pergamino de sombra");
    SetLong("Se trata de un pergamino bastante deteriorado. Te fijas un poco "
        "m�s y puedes observar que tiene escritas varias frases con una "
        "letra clara y bonita.\nEn el encabezado lees 'hechizo sombra'.\n"
        "Quiz�s si lo intentases hasta podr�as hacerlo o incluso memorizarlo.\n");
    SetIds(({"pergamino","sombra","hoja","papel"}));
    SetValue(50000);
    SetWeight(100);
    Set(P_GENDER,GENERO_MASCULINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    SetCanMemorize(1);
    SetCanCast(1);
    SetMaxCast(1);
    SetScrollID("sombra");
    SetDestructMsg("El pergamino comienza a arder en tus manos y se "
        "convierte en ceniza.\n");
}


