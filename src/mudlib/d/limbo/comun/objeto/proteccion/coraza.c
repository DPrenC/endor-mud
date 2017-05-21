/*
DESCRIPCION  : Coraza
FICHERO      : /d/limbo/comun/objeto/proteccion/coraza.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
               28-09-99 [Mirill@Simauria] Adapatación al nuevo combat.c
--------------------------------------------------------------------------------
*/

inherit ARMOUR;
#include <properties.h>
#include <combat.h>

create() {
 ::create();
 SetStandard(AT_MAIL,1,P_SIZE_GENERIC,M_HIERRO);
 AddId("coraza");
 AddAdjective("de hierro");
 SetShort("una coraza");
 SetLong("Es una coraza de hierro. Es un trabajo algo tosco, pero cumple su cometido.\n");
 SetValue(100);
 SetWeight(5000);
 Set(P_GENDER,GENDER_FEMALE);
 SetResetQuality(90);
 Set(P_NOSELL,1);
}


