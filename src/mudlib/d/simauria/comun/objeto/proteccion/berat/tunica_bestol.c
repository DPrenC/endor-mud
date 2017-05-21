/****************************************************************************
Fichero: tunica_bestol.c
Autor: Ratwor
Fecha: 26/11/2007
Descripción: Una túnica para el errante de la Rosa de los vientos.
****************************************************************************/


#include "./path.h"
#include <combat.h>
#include <properties.h>
inherit ARMOUR;

create()
{
    ::create();
    SetStandard(AT_TUNICA, 1,P_SIZE_LARGE,M_TELA);
    SetShort("una oscura túnica");
    SetLong("Es una oscura túnica de tela dura, de un color indeterminado entre "
    "verde oliva, marrón oscuro o quizá azul marino.\n Aunque se nota que está limpia, "
    "la apariencia es de ser notablemente vieja. Destaca alrededor de ambos puños, "
    "unas pequeñas equis bordadas con hilo dorado.\n");
    AddId(({"tunica","túnica","tunica vieja","túnica vieja"}));
    SetResetQuality(100);
}
