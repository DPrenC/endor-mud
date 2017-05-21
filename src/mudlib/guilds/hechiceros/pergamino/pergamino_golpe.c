/*=============================================================*
 |           << GOLDHAI.Magia [w] Woo@simauria >>              |
 *=============================================================*
 |              Creacion............. 08-12-99                 |
 |              Ultima Modificacion...08-12-99                 |
 |                                                             |
 *=============================================================*/

#include <properties.h>
inherit "/obj/pergamino";

create() {
 ::create();

 SetShort("el pergamino del golpe de descarga");
 SetLong("\
Se trata de un pergamino bastante deteriorado. Te fijas un poco más y puedes\n\
observar que tiene escritas varias frases con una letra clara y bonita. En\n\
el encabezado lees 'golpe de descarga' quizás si lo intentases hasta\n\
podrías hacerlo o incluso memorizarlo.\n");
 SetIds(({"pergamino","golpe","hoja","papel"}));
 SetValue(14000);
 SetWeight(100);
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetCanMemorize(1);
 SetCanCast(1);
 SetMaxCast(1);
 SetScrollID("golpe de descarga");
 SetDestructMsg("El pergamino comienza a arder en tus manos y se convierte en ceniza.\n");
}


