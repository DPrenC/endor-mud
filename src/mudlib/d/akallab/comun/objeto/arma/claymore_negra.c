/*
DESCRIPCION  : claymore negra
FICHERO      : claymore_negra.c
BASADA       : espada_negra (Goldhai)
MODIFICACION : 05-03-00 [Angor@Simauria] Creacion
*/

inherit WEAPON;
#include <combat.h>
#include <properties.h>
#include <materials.h>

create()
{
 if (!clonep(TO)) return 1;
 ::create();
 SetStandard(WT_ESPADA,12,P_SIZE_MEDIUM,M_ACERO);
 SetWeight(10000); // Un poco mas de peso
 SetShort("una claymore negra");
 AddId(({"claymore","claymore negra"}));
 SetAds(({"una","gran","pesada"}));
 SetValue(4500);
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetNumberHands(2);
 SetLong("\
Es una pesada espada de hoja recta, de la que sobresalen dos largas hojas\n\
orientadas oblicuamente. Puedes ver claramente que no es un claymore\n\
normal: su color es de un extranyo negro muy oscuro, sin apenas brillo y\n\
parece un trabajo de mas calidad que el normal. Posiblemente sea obra de\n\
todo un maestro armero de la ciudad de Akallab.\n");
SetResetQuality(85);
}


