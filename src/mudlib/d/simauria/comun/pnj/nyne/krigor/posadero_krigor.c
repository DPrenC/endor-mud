    /****************************************************************************
Fichero: posadero_krigor.c
Autor: Ratwor
Fecha: 27/08/2006
Descripci�n: el posadero tabernero de la posada de Krigor.
****************************************************************************/


#include "./path.h"
#include <properties.h>
inherit NPC;

create()
{
    ::create();

    SetStandard("el posadero", "humano", 15, GENDER_MALE);
    SetShort("el posadero");
    SetLong("Este es el posadero del curioso pueblo de Krigor.\n Hasta no hace mucho "
        "se dedicaba a pastar las vacas, pero una grabe enfermedad vacuna le dej� sin "
        "reva�o y decidi� montarse un negocio m�s seguro, que al fin y al cabo el lugar "
        "precisaba de una posada.\n");
    AddId(({"posadero"}));
    InitAChats(9, ({"El posadero grita: �d�jame en paz malnacido!.\n"}));
        InitChats(3, ({"El posadero  te dice: �le puedo ayudar  en algo?.\n",
        "El posadero limpia un vaso.\n",
        "El posadero te dice: si necesita habitaci�n siento decirle que las tengo todas "
        "ocupadas.\n",
        "El posadero te mira esperando que le pidas algo.\n"}));
}
