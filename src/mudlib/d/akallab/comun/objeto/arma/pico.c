/*
DESCRIPCION  : pico para las minas de Zarkam
FICHERO      : /d/akallab/comun/objeto/arma/pico.c
MODIFICACION : 04-11-99 [Angor@Simauria] Creacion
*/	

#include <combat.h>
#include <properties.h>
#include "path.h"

inherit WEAPON;

create()
{
 if (!clonep(TO)) return 1;
 ::create();
 SetStandard(WT_MAZA,4,P_SIZE_GENERIC,M_HIERRO);
 SetWeight(5000); // Aumentado el peso
 SetShort("un pico de minero");
 SetIds(({"pico","pico de minero"}));
 SetValue(1000);
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetNumberHands(1);
 SetLong("Es un vulgar pico de los que usan lo mineros para hacer su trabajo.\n");
}
