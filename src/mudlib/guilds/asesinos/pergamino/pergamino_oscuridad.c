/*=============================================================*
 |           << GOLDHAI.Magia [w] Woo@simauria >>              |
 *=============================================================*
 |              Creacion............. 21-10-99                 |
 |              Ultima Modificacion...21-10-99                 |
 |                                                             |
 *=============================================================*/

#include <properties.h>
inherit "/obj/pergamino";

create() {
 ::create();

 SetShort("un pergamino antiguo");
 SetLong("\
Se trata de un pergamino bastante deteriorado. Te fijas un poco más y puedes\n\
observar que tiene escritas varias frases con una letra clara y bonita. En\n\
el encabezado lees 'conjuro de oscuridad' quizás si lo intentases hasta\n\
podrías hacerlo o incluso memorizarlo.\n");
 SetIds(({"pergamino","oscuridad","hoja","papel"}));
 SetValue(90);
 SetWeight(100);
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetCanMemorize(1);
 SetCanCast(1);
 SetMaxCast(1);
 SetScrollID("oscuridad");
 SetDestructMsg("El pergamino comienza a arder en tus manos y se convierte en ceniza.\n");
}


