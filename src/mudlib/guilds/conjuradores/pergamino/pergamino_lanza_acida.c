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
    SetShort("el pergamino de lanza de �cido");
    SetLong("Se trata de un pergamino bastante deteriorado.\nTe fijas un poco m�s y puedes "
        "observar que tiene escritas varias frases con una letra clara y bonita.\nEn el "
        "encabezado lees 'Conjuro lanza de acido'.\nquiz�s si lo intentases hasta podr�as "
        "hacerlo o incluso memorizarlo.\n");
    SetIds(({"pergamino","lanza de �cido","hoja","papel"}));
    SetValue(12000);
    SetWeight(100);
    Set(P_GENDER,GENERO_MASCULINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    SetCanMemorize(1);
    SetCanCast(1);
    SetMaxCast(1);
    SetScrollID("lanza de acido");
    SetDestructMsg("El pergamino comienza a arder en tus manos y se convierte en ceniza.\n");
}


