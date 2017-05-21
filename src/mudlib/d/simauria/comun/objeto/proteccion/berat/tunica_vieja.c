/****************************************************************************
Fichero: tunica_vieja.c
Autor: Ratwor
Fecha: 12/05/2010
Descripci�n: Una t�nica para el borracho preso de berat.
****************************************************************************/


#include <combat.h>
#include <properties.h>
inherit ARMOUR;

create()
{
    ::create();
    SetStandard(AT_TUNICA, 1,P_SIZE_LARGE,M_TELA);
    SetShort("una t�nica vieja");
    SetLong("Es una horrenda t�nica totalmente destrozada por multitud de sitios, "
    "donde le cuelgan distintos jirones. Su color es indescriptible debido a la "
    "cantidad de suciedad que lleva encima y la multitud de zonas desilachadas.\n") ;
    AddId(({"tunica","t�nica", "ropa"}));
    AddAdjective("vieja");
    SetResetQuality(70);
    SetQuality(70);
    Set(P_GENDER, GENDER_FEMALE);
}
