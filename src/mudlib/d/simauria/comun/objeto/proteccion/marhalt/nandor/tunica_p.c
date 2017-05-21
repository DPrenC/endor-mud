/****************************************************************************
Fichero: tunica_p.c
Autor: Ratwor
Fecha: 14/05/2010
Descripci�n: Una t�nica de talla peque�a
****************************************************************************/


#include <combat.h>
#include <properties.h>
inherit ARMOUR;

create()
{
    ::create();
    SetStandard(AT_TUNICA, 1,P_SIZE_SMALL,M_TELA);
    SetShort("una peque�a t�nica");
    SetLong("Es una peque�a t�nica verde oscuro,  con el cuello y los pu�os reforzados "
    "de cuero.\n Por algunas zonas de la parte baja presenta un tono algo "
    "descolorido.\n") ;
    AddId(({"tunica","t�nica", "ropa"}));
    AddAdjective(({"peque�a", "verde", "oscuro"}));
    AddSubDetail(({"cuello", "pu�os", "punyos"}), "Es de cuero de notable calidad.\n");
    Set(P_GENDER, GENDER_FEMALE);
}
