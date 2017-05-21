/****************************************************************************
Fichero: salndlin.c
Autor: Kastwey
Fecha: 07/03/2006
Descripci�n: Un banquero para la ciudad de Crowy
****************************************************************************/


#include <properties.h>

inherit NPC;

create()
{
    ::create();
    SetStandard("Salndlin","elfo",15, GENDER_MALE);
    SetShort("Salndlin, el banquero");
    SetLong("Salndlin es el elfo que lleva la sucursal bancaria de la ciudad. "
            "Tiene una mirada vivaz e inteligente. Seg�ramente ser�a dif�cil de enga�ar "
            "en una transacci�n.\n");
}



