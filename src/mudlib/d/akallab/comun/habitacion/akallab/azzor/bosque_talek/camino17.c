/*
DESCRIPCION  : camino a traves del bosque de Talek
FICHERO      : camino17.c
MODIFICACION : 13-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_TALEK("camino");

create()
{
    ::create();
   SetIntShort("la orilla del río");
    SetIntLong("Te encuentras en la orilla del caudaloso río Kuneii. Un "
        "puente de piedra al sur permite aquí al camino que atraviesa el "
        "bosque cruzar sobre este río. La humedad del río hace que en esta "
        "zona el bosque sea más verde y frondoso. Oyes el ruido de unas "
        "cataratas al oeste de aquí.\n");
    AddDetail(({"puente","puente de piedra"}),"Un ancho puente de piedra "
        "permite atravesar el caudaloso río Kuneii. Es un puente de varios "
        "ojos con gruesos pilares firmemente asentados en el cauce del río. "
        "Se haya en buen estado, aunque ya se nota el efecto de la humedad "
        "en el.\n");
    AddDetail(({"río","kuneii","río kuneii","río Kuneii"}),"El río Kuneii "
        "recorre este valle de este a oeste. Es un río caudaloso plagado de "
        "rápidos que hacen que no sea navegable. Nace en el vecino valle de "
        "Zarkam y a través de las Cataratas de Nurr atraviesa las Montañas "
        "Negras y entra en el valle. Desemboca al sur de la ciudad de Azzor.\n");
    SetIntNoise("Oyes el ruido de unas cataratas.\n");
    AddExit("nordeste",BOSQUE_TALEK("camino18"));
    AddExit("sur",BOSQUE_TALEK("camino16"));
    AddExit("oeste",BOSQUE_TALEK("cataratas"));
    AddExit("este",BOSQUE_TALEK("bosque60"));
}
