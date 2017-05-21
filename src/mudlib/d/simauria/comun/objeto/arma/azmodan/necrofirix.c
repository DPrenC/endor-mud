/*****************************************************/
//
//	"necrofirix"
//
//	necrofirix o cetro cadavérico (maza) WC: 7
//	11-12-01: Kodex -> Creación
//	11-12-01: Kodex -> Modificación
//
/******************************************************/

inherit WEAPON;

#include <combat.h>
#include <properties.h>
#include "../path.h"
create()
{
::create();

SetStandard(WT_MAZA,7,P_SIZE_MEDIUM,M_HUESO);

SetShort("un necrofirix");
SetLong(W("Ves un cetro fabricado en madera de ent pero ya "
"muerta y descolorida, está adornado con unas plumas místicas "
"y en la punta tiene un cráneo humano. Es un arma aterradora"
", te preguntas quién fue el perturbado que la engendró.\n"));
SetIds(({"arma","necrofirix","cetro"}));
Set(P_GENDER,GENERO_MASCULINO);
Set(P_NUMBER,NUMERO_SINGULAR);
SetNumberHands(1);
}