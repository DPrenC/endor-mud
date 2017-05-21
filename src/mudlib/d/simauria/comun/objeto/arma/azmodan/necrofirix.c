/*****************************************************/
//
//	"necrofirix"
//
//	necrofirix o cetro cadav�rico (maza) WC: 7
//	11-12-01: Kodex -> Creaci�n
//	11-12-01: Kodex -> Modificaci�n
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
"muerta y descolorida, est� adornado con unas plumas m�sticas "
"y en la punta tiene un cr�neo humano. Es un arma aterradora"
", te preguntas qui�n fue el perturbado que la engendr�.\n"));
SetIds(({"arma","necrofirix","cetro"}));
Set(P_GENDER,GENERO_MASCULINO);
Set(P_NUMBER,NUMERO_SINGULAR);
SetNumberHands(1);
}