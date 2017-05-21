/****************************************************************************
Fichero: kluer.c
Autor: Ratwor
Fecha: 23/03/2008
Descripci�n: El tendero de la tienda de Krigor.
****************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;

create(){
    ::create();
    SetStandard("Kluer", "humano", 12, GENDER_MALE);
    SetShort("kluer, el viejo tendero");
    SetLong("Kluer es el tendero de Krigor, y lo ha sido desde hace muchos a�os ya "
            "que �l es uno de los m�s antiguos del lugar.\n Es un viejo algo desordenado, "
            "pero amable.\n");
        AddId(({"tendero","viejo", "kluer","Kluer"}));
Set(P_CANT_LURE,1);
}
