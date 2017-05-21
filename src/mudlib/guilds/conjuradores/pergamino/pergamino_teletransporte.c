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
    SetShort("el pergamino de puerta dimensional");
    SetLong("Se trata de un pergamino bastante deteriorado.\nTe fijas un poco más y puedes "
        "observar que tiene escritas varias frases con una letra clara y bonita.\nEn el "
        "encabezado lees 'Conjuro puerta dimensional'.\nquizás si lo intentases hasta podrías "
        "hacerlo o incluso memorizarlo.\n");
    SetIds(({"pergamino","puerta","hoja","papel"}));
    SetValue(20000);
    SetWeight(100);
    Set(P_GENDER,GENERO_MASCULINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
    SetCanMemorize(1);
    SetCanCast(1);
    SetMaxCast(1);
    SetScrollID("puerta dimensional");
    SetDestructMsg("El pergamino comienza a arder en tus manos y se convierte en ceniza.\n");
}


