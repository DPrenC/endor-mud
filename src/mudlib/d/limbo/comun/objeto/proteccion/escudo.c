/*
DESCRIPCION  : Escudo
FICHERO      : /d/limbo/comun/objeto/proteccion/escudo.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
               28-09-99 [Mirill@Simauria] Adapatación al nuevo combat.c
--------------------------------------------------------------------------------
*/

inherit ARMOUR;
#include <properties.h>
#include <combat.h>

create() {
 ::create();
 SetStandard(AT_SHIELD,1,P_SIZE_MEDIUM);
 AddId("escudo");
 AddAdjective("mediano");
 SetShort("un escudo");
 SetLong("Es un escudo corriente de tamaño mediano.\n");
 SetValue(15);
 SetWeight(5000);
 SetResetQuality(100);
 Set(P_NOSELL,1);
}


