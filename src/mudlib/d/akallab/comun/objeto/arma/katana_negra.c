/*
DESCRIPCION  : katana negra
FICHERO      : katana_negra.c
MODIFICACION : 05-03-00 [Angor@Simauria] Creacion
		19-01-05 [Gw] Quito el int del create y un return 1. que el create
		es void coñe.
*/

inherit WEAPON;
#include <combat.h>
#include <properties.h>
#include <materials.h>

create()
{

 ::create();
 SetStandard(WT_ESPADA,9,P_SIZE_MEDIUM,M_ACERO);
 SetShort("una katana negra");
 AddId(({"espada","katana","katana negra"}));
 SetAds(({"una","larga","afilada","negra"}));
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetNumberHands(1);
 SetLong("\
Es una espada de acero de mediano tamanyo, estrecha, recta y muy afilada.\n\
Puedes ver claramente que no es un katana normal ya que su color es de un\n\
extranyo negro muy oscuro, sin apenas brillo y por que parece un trabajo\n\
de mas calidad que el normal. Posiblemente sea obra de todo un maestro\n\
armero de la ciudad de Akallab.\n");
}
