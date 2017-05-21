/*=============================================================*
 |           << GOLDHAI.Magia [w] Woo@simauria >>              |
 *=============================================================*
 |              Creacion............. 21-10-99                 |
 |              Ultima Modificacion...21-10-99                 |
 |                                                             |
 *=============================================================*/

#include <properties.h>
inherit "/obj/pergamino";


create()
{
    ::create();
    SetShort("el pergamino de enjambre");
    SetLong("Se trata de un pergamino bastante deteriorado.\nTe fijas un poco m�s y puedes "
        "observar que tiene escritas varias frases con una letra clara y bonita.\nEn el "
        "encabezado lees 'Conjuro enjambre'.\nquiz�s si lo intentases hasta podr�as "
        "hacerlo o incluso memorizarlo.\n");
    SetIds(({"pergamino","enjambre","hoja","papel"}));
    SetValue(4000);
    SetWeight(100);
    Set(P_GENDER,GENERO_MASCULINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    SetCanMemorize(1);
    SetCanCast(1);
    SetMaxCast(1);
    SetScrollID("enjambre");
    SetDestructMsg("El pergamino comienza a arder en tus manos y se convierte en ceniza.\n");
}


