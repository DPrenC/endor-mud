/****************************************************************************
Fichero: jubon.c
Autor: Ratwor
Fecha: 17/04/2008
Descripción: un jubón negro de terciopelo.
Modificación: 04/01/2012 Yalin
Corrijo sangrado y tipo: es jubón, no jugón.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
inherit ARMOUR;

create()
{
    ::create();
    SetIds(({"jubon", "jubón", "jubón negro", "jubon negro"}));
        SetStandard(AT_TABARDO,0,P_SIZE_NORMAL,M_TELA);
    SetShort("un jubón negro de terciopelo");
    Set(P_GENDER,GENERO_MASCULINO);
      Set(P_NUMBER,NUMERO_SINGULAR);
    SetLong("Es un jubón del más lujoso terciopelo, decorado en hombros y puños por hilo "
    "de plata dibujando finos bordados.\n");
    SetWeight(950);
    SetValue(5500);
}
