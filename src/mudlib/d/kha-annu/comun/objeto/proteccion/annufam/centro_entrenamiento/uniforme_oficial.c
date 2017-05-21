/****************************************************************************
Fichero: uniforme_oficial.c
Autor: Tagoras
Creaci�n: 28/02/2009
Descripci�n: Uniforme para los oficiales de Annufam
****************************************************************************/

#include "./path.h"
#include <materials.h>
#include <properties.h>
#include <combat.h>


inherit ARMOUR;

public void create()
{
    ::create();
    SetStandard(AT_TABARDO, 8, P_SIZE_NORMAL, M_TELA);
    SetShort("un uniforme de oficial");
    SetLong("Se trata del uniforme de los oficiales del ej�rcito enano de Kha-annu. Es una t�nica de color verde y marr�n en cuyo pecho ves bordada la cabeza de un le�n y en cuyos hombros est�n los galones que determinan la graduaci�n del oficial.\n");
    AddId(({"uniforme","uniforme oficial","uniforme de tela"}));
	AddSubDetail("galones", "Es una cinta de cuero negro a la que va cosida una estrella de cinco puntas.\n");
}
