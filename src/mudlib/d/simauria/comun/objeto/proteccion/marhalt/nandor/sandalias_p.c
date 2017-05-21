/****************************************************************************
Fichero: sandalias_p.c
Autor: Ratwor
Fecha: 14/05/2010
Descripci�n: unas sandalias de talla peque�a
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_BOTAS, 1, P_SIZE_SMALL, M_CUERO);
    SetShort("unas sandalias peque�as");
    SetLong("Son unas peque�as sandalias de cuero, muy c�modas para viajar.\n");
    SetWeight(300);
    SetIds(({"sandalias"}));
    AddAdjective(({"de", "cuero", "peque�as"}));
    Set(P_GENDER, GENDER_FEMALE);
    Set(P_NUMBER, NUMBER_PLURAL); 
}
