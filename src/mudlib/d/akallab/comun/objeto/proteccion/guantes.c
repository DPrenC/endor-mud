/*
DESCRIPCION  : Un casco
FICHERO      : /d/limbo/comun/objeto/proteccion/casco.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
               04-12-98 [Nemesis@Simauria] Aumentado el peso
--------------------------------------------------------------------------------
*/

inherit ARMOUR;
#include <properties.h>
#include <combat.h>

create() {
 ::create();
 SetStandard(AT_GLOVES, 1, P_SIZE_MEDIUM, M_ACERO);
 AddId(({"guantes","guantes de combate"}));
 SetShort("unos guantes de combate");
 SetLong("Son un par de guantes de combate. Estan hechos con una tupida malla de metal.\n");
 Set(P_NOSELL,1);
}
