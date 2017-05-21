/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque56.c
MODIFICACION : 13-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
   SetIntShort("la orilla del r�o");
    SetIntLong("Te encuentras en la orilla del r�o Kuneii que cruza este "
        "bosque de Talek.\n"+QueryIntLong()+"Al oeste de aqu�, un puente "
        "de piedra permite cruzar el r�o.\n");
    AddDetail(({"puente","puente de piedra"}),"Al oeste de aqu�, un puente "
        "de piedra permite cruzar el r�o.\n");
    AddDetail(({"r�o","kuneii","r�o kuneii","r�o Kuneii"}),"El r�o Kuneii "
        "recorre este valle de este a oeste. Es un r�o caudaloso plagado de "
        "r�pidos que hacen que no sea navegable. Nace en el vecino valle de "
        "Zarkam y a trav�s de las Cataratas de Nurr atraviesa las Monta�as "
        "Negras y entra en el valle. Desemboca al sur de la ciudad de Azzor.\n");
    SetIntSmell("Hueles un fresco aroma a lavanda...\n");
    AddExit("nordeste",BOSQUE_TALEK("bosque61"));
    AddExit("suroeste",BOSQUE_TALEK("camino15"));
    AddExit("este",BOSQUE_TALEK("bosque57"));
}

