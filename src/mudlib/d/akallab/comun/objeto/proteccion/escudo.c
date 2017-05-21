/*
DESCRIPCION  : Escudo
FICHERO      : /d/limbo/comun/objeto/proteccion/escudo.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

inherit ARMOUR;
#include <properties.h>
#include <combat.h>

create() {
 ::create();
 SetStandard(AT_SHIELD, 1, P_SIZE_MEDIUM, M_ACERO);
 AddId("escudo");
 AddAdjective("mediano");
 SetShort("un escudo");
 SetLong("Es un escudo corriente de tamanyo mediano.\n");
 Set(P_NOSELL,1);
}


