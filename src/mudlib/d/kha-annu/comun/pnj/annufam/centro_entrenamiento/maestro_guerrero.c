/**************************************************************************
fichero: maestro_guerrero.c
Autor: Tagoras.
Creaci�n: 28/02/2009
Descripci�n: Un maestro guerrero del centro
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

    SetStandard("un maestro","enano", ([GC_GUERRERO:(54+random(4))]),GENDER_MALE);
    AddId(({"maestro"}));
    SetShort("un maestro guerrero");
    SetLong("Se trata de uno de los maestros guerreros de Annufam, no te cabe ninguna duda. La musculatura de sus brazos, sus cicatrices marc�ndole el rostro, las dos hachas que empu�a, su coraza, y sobretodo los galones de su uniforme te hacen pensar que este enano es una de las autoridades del centro y adem�s una mala bestia capaz de arrancarte la cabeza al menor descuido. Ser� mejor que lleves cuidado si pretendes batirte con �l.\n");
    InitChats(3,({"El maestro guerrero refunfu�a.\n", "El maestro guerrero dice: Cada d�a los reclutas son m�s ineptos.\n"}));
	AddItem(PROT_CENTRO_ANNUFAM("uniforme_oficial"),REFRESH_REMOVE,SF(wearme));
	call_out("arma", 1);
}
