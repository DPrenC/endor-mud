	/****************************************************************************
	Fichero: lanza_1mano.c
	Autor: Buh
	Fecha: 25/11/2007
	Descripción: Una lanza.
	****************************************************************************/

#include <properties.h>
#include <combat.h>
inherit WEAPON;
create()
{
    ::create();
    SetStandard(WT_LANZA, 6, P_SIZE_GENERIC, M_HIERRO);
    SetShort("una lanza");
    SetLong("La lanza está formada por un sencillo mango de madera de unos dos metros "
    "de longitud con una punta de hierro de forma oval encajada en el extremo superior.\n "
    "Es un arma muy sencilla y de fácil manejo, utilizada por las formaciones "
    "de infantería que crean un muro de afiladas puntas  difícil de  franquear.\n");
    AddId(({"lanza", "arma"}));
    Set(P_GENDER, GENDER_FEMALE);
    SetWeight(1750);
    SetNumberHands(1);
}
