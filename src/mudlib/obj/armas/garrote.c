/* Fichero: garrote.c */


#include <combat.h>
#include <properties.h>

inherit WEAPON;


create()
{
 ::create();
 SetStandard(WT_GARROTE, 6,P_SIZE_GENERIC,M_MADERA);
 SetShort("un garrote");
 SetLong(
 "Se trata de una gruesa sección de madera descortezada y toscamente tallada en la "
 "parte inferior para facilitar la sujección. El grosor de esta tosca arma se va "
 "incrementando hacia la parte delantera para que todo el peso se concentre en la "
 "superficie de impacto. Los garrotes son una de las armas más fáciles de construir, "
 "compensando lo engorroso de su manejo con los demoledores golpes que son capaces de ejecutar.\n"
 "Solo las razas más brutales y bárbaras suelen utilizar garrotes de forma habitual.\n");
}