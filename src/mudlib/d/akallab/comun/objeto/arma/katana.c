/*
DESCRIPCION  : katana normal
FICHERO      : katana.c
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
 SetStandard(WT_ESPADA,6,P_SIZE_MEDIUM,M_ACERO);
 SetShort("una katana");
 AddId(({"espada","katana"}));
 SetAds(({"una","larga","afilada"}));
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetNumberHands(1);
 SetLong("\
Es una espada de acero de mediano tamanyo, estrecha, recta y muy afilada.\n");
}
