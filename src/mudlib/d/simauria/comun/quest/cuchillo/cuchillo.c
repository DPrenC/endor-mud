/*
DESCRIPCION  : el cuchillo de Malmabeth
FICHERO      : /d/simauria/comun/quest/cuchillo/cuchillo.c
MODIFICACION : 14-6-00 [Maler] Creacion.
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <properties.h>
#include <combat.h>
inherit WEAPON;

create()
{
    ::create();
    SetStandard(WT_CUCHILLO,1,P_SIZE_GENERIC,M_HIERRO,GENERO_MASCULINO);
    AddId(({"cuchillo","quest_cuchillo_berat"}));
    AddAdjective(({"curtir","para"}));
    SetShort("un cuchillo para curtir");
    SetLong("Es un cuchillo para curtir. El mango es de madera, y la hoja parece estar muy "
        "desgastada por el uso abusivo, y por haber sido afilado demasiadas veces. No crees "
        "que sea de ninguna utilidad.\n");
    SetWeight(100);
    SetValue(5);
    Set(P_CANT_STEAL,1);
    Set(P_NOGIVE, 1);
    Set(P_NODROP, 1);
    Set(P_NOSELL, 1);
    Set(P_NOBUY, 1);
}
