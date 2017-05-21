/****************************************************************************
Fichero: uniforme_oficial.c
Autor: Tagoras
Creación: 28/02/2009
Descripción: Uniforme para los oficiales de Annufam
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
    SetLong("Se trata del uniforme de los oficiales del ejército enano de Kha-annu. Es una túnica de color verde y marrón en cuyo pecho ves bordada la cabeza de un león y en cuyos hombros están los galones que determinan la graduación del oficial.\n");
    AddId(({"uniforme","uniforme oficial","uniforme de tela"}));
	AddSubDetail("galones", "Es una cinta de cuero negro a la que va cosida una estrella de cinco puntas.\n");
}
