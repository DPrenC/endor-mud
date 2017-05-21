/****************************************************************************
Fichero: chaleco_p.c
Autor: Ratwor
Fecha: 14/05/2010
Descripci�n: un chaleco de talla peque�a
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_TUNICA, 1, P_SIZE_SMALL, M_TELA);
    SetShort("un chaleco amarillo");
    SetLong("Es un peque�o chaleco de tela de color amarillo con unas florecillas "
    "bordadas en el pecho.\n");
    SetIds(({"chaleco", "ropa"}));
    AddAdjective(({"amarillo", "de", "tela", "peque�o"}));
    SetWeight(300);
    Set(P_GENDER, GENDER_MALE);

}
