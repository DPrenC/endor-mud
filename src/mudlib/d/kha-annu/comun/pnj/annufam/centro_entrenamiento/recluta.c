/**************************************************************************
fichero: recluta.c
Autor: Tagoras.
Creaci�n: 28/02/2009
Descripci�n: Un recluta del centro
**************************************************************************/

#include "./path.h"
#include <guild.h>
#include <properties.h>
#include <combat.h>

inherit PNJ_CENTRO_ANNUFAM("base_militar");

public void create()
{
    ::create();
	object room;

    seteuid(getuid());

    SetStandard("un recluta","enano", ([GC_GUERRERO:(42+random(4))]), GENDER_MALE);
    AddId(({"recluta"}));
    SetShort("un recluta enano");
    SetLong("Es uno de los reclutas del centro de adiestramiento de guerreros enanos de Annufam. Se le ve muy joven y con cierta cara de asustado. Seguro que lleva poco tiempo aqu� y todav�a no se ha acostumbrado del todo a la vor�gine de la lucha.\n");
    InitChats(3,({"El recluta suspira.\n", "El recluta dice: �Ojal� me vaya bien en el examen de hacha!\n"}));
	AddItem(PROT_CENTRO_ANNUFAM("uniforme_soldados"),REFRESH_REMOVE,SF(wearme));
	call_out("arma", 1);
}
