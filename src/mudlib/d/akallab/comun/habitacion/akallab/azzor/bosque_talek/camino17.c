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
   SetIntShort("la orilla del r�o");
    SetIntLong("Te encuentras en la orilla del caudaloso r�o Kuneii. Un "
        "puente de piedra al sur permite aqu� al camino que atraviesa el "
        "bosque cruzar sobre este r�o. La humedad del r�o hace que en esta "
        "zona el bosque sea m�s verde y frondoso. Oyes el ruido de unas "
        "cataratas al oeste de aqu�.\n");
    AddDetail(({"puente","puente de piedra"}),"Un ancho puente de piedra "
        "permite atravesar el caudaloso r�o Kuneii. Es un puente de varios "
        "ojos con gruesos pilares firmemente asentados en el cauce del r�o. "
        "Se haya en buen estado, aunque ya se nota el efecto de la humedad "
        "en el.\n");
    AddDetail(({"r�o","kuneii","r�o kuneii","r�o Kuneii"}),"El r�o Kuneii "
        "recorre este valle de este a oeste. Es un r�o caudaloso plagado de "
        "r�pidos que hacen que no sea navegable. Nace en el vecino valle de "
        "Zarkam y a trav�s de las Cataratas de Nurr atraviesa las Monta�as "
        "Negras y entra en el valle. Desemboca al sur de la ciudad de Azzor.\n");
    SetIntNoise("Oyes el ruido de unas cataratas.\n");
    AddExit("nordeste",BOSQUE_TALEK("camino18"));
    AddExit("sur",BOSQUE_TALEK("camino16"));
    AddExit("oeste",BOSQUE_TALEK("cataratas"));
    AddExit("este",BOSQUE_TALEK("bosque60"));
}
