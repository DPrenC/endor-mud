/*
DESCRIPCION  : Un casco
FICHERO      : /d/limbo/comun/objeto/proteccion/casco.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
               28-09-99 [Mirill@Simauria] Adapatación al nuevo combat.c
               10-10-99 [Woo@Simauria] Retocado
--------------------------------------------------------------------------------
*/

inherit ARMOUR;
#include <properties.h>
#include <combat.h>

create() {
 ::create();
 SetStandard(AT_HELMET,1,P_SIZE_MEDIUM);
 AddId("casco");
 AddAdjective("abollado");
 SetShort("un casco");
 SetLong(
   "Es un casco abierto y sin visera. El material no parece muy bueno y además está\n"
   "un poco abollado, sin duda debido a usos anteriores.\n");
 SetValue(100);
 SetWeight(2000);
 SetResetQuality(90);
 Set(P_NOSELL,1);
}




