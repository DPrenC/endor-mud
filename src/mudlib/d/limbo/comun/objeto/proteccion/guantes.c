/*
DESCRIPCION  : Un casco
FICHERO      : /d/limbo/comun/objeto/proteccion/casco.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
               28-09-99 [Mirill@Simauria] Adapatación al nuevo combat.c
--------------------------------------------------------------------------------
*/

inherit ARMOUR;
#include <properties.h>
#include <combat.h>

create() {
 ::create();
 SetStandard(AT_GLOVES,1,P_SIZE_MEDIUM,M_HIERRO);
 AddId(({"guantes","guantes de combate"}));
 SetShort("unos guantes de combate");
 SetLong("Son un par de guantes de combate. Están hechos con una tupida malla de metal.\n");
 SetValue(10);
 SetWeight(250);
 SetResetQuality(90);
 Set(P_NOSELL,1);
}
