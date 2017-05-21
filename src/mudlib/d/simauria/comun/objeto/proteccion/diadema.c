/****************************************************************************
Fichero: diadema.c
Autor: Ratwor
Fecha: 18/04/2008
Descripci�n: una diadema enjoyada.
****************************************************************************/

#include <combat.h>
#include <properties.h>

inherit ARMOUR;

create()
{
   ::create();
    SetStandard(AT_TIARA,0,P_SIZE_LARGE,M_HIERRO);
    SetWeight(150);
    AddId(({"diadema", "diadema lujosa", "diadema dorada"}));
    RemoveId("casco");
    SetShort("una diadema dorada");
    Set(P_GENDER,GENERO_FEMENINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
   SetLong("Se trata de un fino trabajo de orfebrer�a, la base es oro laminado, y "
   "las incrustaciones son de rub�es y lapisl�zuli en forma de l�grima.\n");
   SetValue(10000);
}

