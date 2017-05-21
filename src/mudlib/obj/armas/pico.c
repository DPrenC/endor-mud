/* pico.c */

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
 ::create();
 SetStandard(WT_PICO,10,P_SIZE_GENERIC,M_HIERRO);
 SetShort("un pico de guerra");
 SetIds(({"pico","pico pesado", "pico de guerra"}));
 SetNumberHands(2);
 SetLong(
 "Es la versión militar de la típica herramienta de minería. Está formado por un mango "
 "de algo más de un metro de largo, reforzado ´con hierro en el extremo y en la parte "
 "delantera. La cabeza es una larga sección de hierro macizo, curvo y ahusado hacia "
 "los extremos. Es un arma temible y potente en manos expertas, sobre todo si su "
 "portador es un robusto enano.\n");
 }