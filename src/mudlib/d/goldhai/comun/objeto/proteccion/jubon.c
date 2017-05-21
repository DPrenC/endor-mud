/****************************************************************************
Fichero: jubon.c
Autor: Ratwor
Fecha: 17/04/2008
Descripci�n: un jub�n negro de terciopelo.
Modificaci�n: 04/01/2012 Yalin
Corrijo sangrado y tipo: es jub�n, no jug�n.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
inherit ARMOUR;

create()
{
    ::create();
    SetIds(({"jubon", "jub�n", "jub�n negro", "jubon negro"}));
        SetStandard(AT_TABARDO,0,P_SIZE_NORMAL,M_TELA);
    SetShort("un jub�n negro de terciopelo");
    Set(P_GENDER,GENERO_MASCULINO);
      Set(P_NUMBER,NUMERO_SINGULAR);
    SetLong("Es un jub�n del m�s lujoso terciopelo, decorado en hombros y pu�os por hilo "
    "de plata dibujando finos bordados.\n");
    SetWeight(950);
    SetValue(5500);
}
