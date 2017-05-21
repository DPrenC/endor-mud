/*
DESCRIPCION  : katana Urkaz
FICHERO      : katana_urkaz.c
BASADA       : cintia.c (Goldhai)
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
 SetStandard(WT_ESPADA,11,P_SIZE_MEDIUM,M_ACERO);
 SetShort("una katana 'Urkaz'");
 SetWeight(QueryWeight()+1000); // Un poco mas de peso
 SetIds(({"espada","katana","katana urkaz","urkaz","Urkaz","katana Urkaz"}));
 SetAds(({"una","larga","afilada","urkaz","Urkaz"}));
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetNumberHands(1);
 SetLong("\
Es una espada de acero de mediano tamanyo, estrecha, recta y muy afilada.\n\
Esta debe ser una de las pocas Urkaz que existen, un muy raro tipo de katana.\n\
Su fabricacion es un secreto muy bien guardado y solo unos pocos de los\n\
mejores armeros de Akallab, tras toda una vida de experiencia, son capaces\n\
de forjarlas.\n");
}
