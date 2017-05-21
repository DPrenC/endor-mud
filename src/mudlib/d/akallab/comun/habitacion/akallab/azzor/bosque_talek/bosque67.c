/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque67.c
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
    SetIntLong("Te hallas en la orilla del r�o Kuneii que divide este bosque "
        "en dos a su paso.\n"+QueryIntLong());
    AddDetail(({"r�o","kuneii","r�o kuneii","r�o Kuneii"}),"El r�o Kuneii "
        "recorre este valle de este a oeste. Es un r�o caudaloso plagado de "
        "r�pidos que hacen que no sea navegable. Nace en el vecino valle de "
        "Zarkam y a trav�s de las Cataratas de Nurr atraviesa las Monta�as "
        "Negras y entra en el valle. Desemboca al sur de la ciudad de Azzor.\n");
    SetIntSmell("Hueles el fresco aroma del bosque y la humedad del r�o.\n");
    AddExit("oeste",BOSQUE_TALEK("bosque66"));
    AddExit("este",BOSQUE_TALEK("bosque68"));
}
