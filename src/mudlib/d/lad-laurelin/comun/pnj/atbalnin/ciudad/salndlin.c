/****************************************************************************
Fichero: salndlin.c
Autor: Kastwey
Fecha: 07/03/2006
Descripción: Un banquero para la ciudad de Crowy
****************************************************************************/


#include <properties.h>

inherit NPC;

create()
{
    ::create();
    SetStandard("Salndlin","elfo",15, GENDER_MALE);
    SetShort("Salndlin, el banquero");
    SetLong("Salndlin es el elfo que lleva la sucursal bancaria de la ciudad. "
            "Tiene una mirada vivaz e inteligente. Segúramente sería difícil de engañar "
            "en una transacción.\n");
}



