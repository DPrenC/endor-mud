/*
DESCRIPCION  : daga con gemas incrustadas en la
FICHERO      : /d/limbo/comun/objeto/arma/daga_joya.c
MODIFICACION : 20-01-98 [angor] Creacion.
               28-09-99 [Mirill@Simauria] Adapatación al nuevo combat.c
               10-10-99 [Woo] Retocado...
*/

inherit WEAPON;

#include <properties.h>

#include <combat.h>

/* No es un arma normal: tiene valor como joya, como arma es mediocre*/
create() {
 ::create();
 SetStandard(WT_CUCHILLO,1,P_SIZE_MEDIUM,M_ORO);
 SetShort("una daga con joyas incrustadas");
 SetLong("Es una pequeña daga con varias inscripciones en su hoja y una empuñadura en\n"
 "la que se hayan incrustadas varias con piedras preciosas. Debe valer bastante\n"
 "dinero.\n");
 AddId("daga");
 AddAdjective("pequenya");
 AddAdjective("pequeña");
 Set(P_GENDER, GENDER_FEMALE);
 SetNumberHands(1);
 SetValue(500);
 SetResetQuality(100);
}
