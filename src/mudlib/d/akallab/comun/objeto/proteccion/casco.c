/*
DESCRIPCION  : Un casco
FICHERO      : /d/limbo/comun/objeto/proteccion/casco.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

inherit ARMOUR;
#include <properties.h>
#include <combat.h>

create() {
 ::create();
 SetStandard(AT_HELMET, 1, P_SIZE_MEDIUM, M_COBRE);
 AddId("casco");
 AddAdjective("abollado");
 SetShort("un casco");
 SetLong(
   "Es un casco abierto y sin visera. El material no parece muy bueno y ademas esta "
   "un poco abollado, sin duda debido a usos anteriores.\n");
 Set(P_NOSELL,1);
}




