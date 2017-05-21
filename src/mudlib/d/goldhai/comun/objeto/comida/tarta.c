/********************************************************/
//
//	"tarta"
//	una tarta de manzana
//
//	20-12-01: Kodex ->Creación y última modificación
//
/********************************************************/

#include <properties.h>
#include "./path.h"
inherit FOOD;

create()
{
::create();
SetFoodKind("food");
SetFoodMsgs("Saboreas una deliciosa tarta de manzana.\n");
SetFoodStuff(40);
SetFoodHeal(15);
SetShort("una tarta de manzana");
SetLong(W("Es una deliciosa tarta de manzana, la especialidad de los gnomos"
". Parece recién horneada.\n"));
SetSmell("Huele que alimenta...\n");
AddId("tarta");
AddId("comida");
AddId("tarta de manzana");
Set(P_GENDER,GENERO_FEMENINO);
Set(P_NUMBER,NUMERO_SINGULAR);
SetWeight(300);
SetValue(60);
}