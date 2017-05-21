/****************************************************************************
Fichero: tunica_p.c
Autor: Ratwor
Fecha: 14/05/2010
Descripción: Una túnica de talla pequeña
****************************************************************************/


#include <combat.h>
#include <properties.h>
inherit ARMOUR;

create()
{
    ::create();
    SetStandard(AT_TUNICA, 1,P_SIZE_SMALL,M_TELA);
    SetShort("una pequeña túnica");
    SetLong("Es una pequeña túnica verde oscuro,  con el cuello y los puños reforzados "
    "de cuero.\n Por algunas zonas de la parte baja presenta un tono algo "
    "descolorido.\n") ;
    AddId(({"tunica","túnica", "ropa"}));
    AddAdjective(({"pequeña", "verde", "oscuro"}));
    AddSubDetail(({"cuello", "puños", "punyos"}), "Es de cuero de notable calidad.\n");
    Set(P_GENDER, GENDER_FEMALE);
}
