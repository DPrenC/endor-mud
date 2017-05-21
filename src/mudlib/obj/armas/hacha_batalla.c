/* fichero: hacha_batalla.c */

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
  ::create();
  SetStandard(WT_HACHA, 8, P_SIZE_GENERIC, M_HIERRO);
  SetShort("un hacha de batalla");
  SetLong(
  "Es una contundente hacha de batalla. El mango de madera tiene casi un metro de "
  "longitud y está forrado con tiras de cuero que se entrecruzan formando multitud de "
  "rombos. El extremo posterior está encajado en una sólida contera metálica muy útil "
  "para golpear de revés. La hoja rematada por una corta punta cónica se ensancha a "
  "partir del mango ampliando la superficie de corte y proporcionando peso al arma.\n"
  
  "Las hachas de batalla son una de las armas preferidas por la raza de los Enanos que "
  "suelen combinarlas con un escudo y manejarlas con excelentes resultados.\n"
  "Sin duda un arma temible en las manos adecuadas aunque resulta algo pesada y requiere "
  "de una constitución poderosa y un férreo entrenamiento para manejarla adecuadamente.\n");
}