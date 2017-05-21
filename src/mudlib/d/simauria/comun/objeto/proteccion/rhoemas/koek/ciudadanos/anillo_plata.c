/****************************************************************************
Fichero: anillo_plata.c
Autor: Dharkus
Fecha: 30/05/2010
Descripción: Un anillo de plata.
****************************************************************************/


#include <properties.h>
#include <combat.h>
inherit ARMOUR;

create() {
    ::create();
    SetStandard(AT_ANILLO,0,P_SIZE_LARGE,M_PLATA);
    SetShort("un anillo de plata");
    SetLong("Es un anillo plateado con una piedra azul.\n");
    AddId("anillo");
    AddAdjective(({"de","plata","plateado"}));
    AddSubDetail(({"piedra","piedra azul"}),
    "Se trata de un pequeño trozo de cuarzo que adorna el anillo.\n");
    SetWeight(50);
}
