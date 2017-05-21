/****************************************************************************
Fichero: uniforme_altriv.c
Autor: Tagoras
Creaci�n: 06/03/2009
Descripci�n: Uniforme para Altriv
****************************************************************************/

#include "./path.h"
#include <materials.h>
#include <properties.h>
#include <combat.h>

inherit ARMOUR;

public void create()
{
    ::create();
    SetStandard(AT_TABARDO, 9, P_SIZE_NORMAL, M_TELA);
    SetShort("el uniforme de Altriv");
    SetLong("Se trata de una t�nica verde y marr�n muy parecida a la del resto de militares enanos pero en la que el le�n bordado en el pecho tiene incrustraciones de oro y diamantes. Est�s seguro que ese uniforme debe valer mucho dinero.\n");
    AddId(({"uniforme","uniforme de altriv","uniforme de tela"}));
	//AddSubDetail("galones", "Es una cinta de cuero negro a la que va cosida una estrella de cinco puntas.\n");
}
