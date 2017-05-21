/*
DESCRIPCION  : camino a traves del bosque de Talek
FICHERO      : camino15.c
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
    SetIntLong("El camino que cruza el bosque llega aqu� a la orilla del "
        "caudaloso r�o Kuneii. Un puente de piedra al norte de aqu� permite "
        "cruzar este r�o que divide al bosque de Talek en dos mitades. A "
        "causa de la humedad del r�o, aqu� el bosque es mucho m�s verde y "
        "frondoso. A lo lejos se escucha el ruido de unas cataratas.\n");
    AddDetail(({"puente","puente de piedra"}),"Un ancho puente de piedra "
        "permite atravesar el caudaloso r�o Kuneii. Es un puente de varios "
        "ojos con gruesos pilares firmemente asentados en el cauce del r�o. "
        "Se haya en buen estado, aunque ya se nota el efecto de la humedad "
        "en �l.\n");
    AddDetail(({"r�o","kuneii","r�o kuneii","r�o Kuneii"}),"El r�o Kuneii "
        "recorre este valle de este a oeste. Es un r�o caudaloso plagado de "
        "r�pidos que hacen que no sea navegable. Nace en el vecino valle de "
        "Zarkam y a trav�s de las Cataratas de Nurr atraviesa las Monta�as "
        "Negras y entra en el valle. Desemboca al sur de la ciudad de Azzor.\n");
    SetIntNoise("A lo lejos se escucha el ruido de unas cataratas.\n");
    AddExit("nordeste",BOSQUE_TALEK("bosque56"));
    AddExit("norte",BOSQUE_TALEK("camino16"));
    AddExit("este",BOSQUE_TALEK("camino14"));
}
