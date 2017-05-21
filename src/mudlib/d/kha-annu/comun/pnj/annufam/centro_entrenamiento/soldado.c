/**************************************************************************
fichero: soldado.c
Autor: Tagoras.
Creación: 28/02/2009
Descripción: Un soldado del centro
**************************************************************************/

#include "./path.h"
#include <guild.h>
#include <properties.h>
#include <combat.h>

inherit PNJ_CENTRO_ANNUFAM("base_militar");

public void create()
{
    ::create();

    seteuid(getuid());

    SetStandard("un soldado","enano",([GC_GUERRERO:(46+random(4))]), GENDER_MALE);
    AddId(({"soldado"}));
    SetShort("un soldado enano");
    SetLong("Es un soldado del centro de reclutamiento de guerreros enanos de Annufam. Va vestido con el uniforme marrón y verde del ejército de Kha-annu. Es un enano musculoso y con algunas cicatrices en el rostro y en los brazos que te hacen pensar que éste ya sabe lo que es entrar en combate.\n");
    InitChats(3,({"El soldado suspira.\n", "El soldado dice: La semana que viene ya me dan destino.\n"}));
	AddItem(PROT_CENTRO_ANNUFAM("uniforme_soldados"),REFRESH_REMOVE,SF(wearme));
	call_out("arma", 1);
}
