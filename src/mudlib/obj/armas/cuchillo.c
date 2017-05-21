/*  fichero: cuchillo.c */
#include <combat.h>
#include <properties.h>

inherit WEAPON;

create(){
  ::create();

  SetStandard(WT_CUCHILLO,3,P_SIZE_GENERIC,M_HIERRO);
  SetIds(({"cuchillo"}));
  SetShort("un cuchillo");
  SetLong(
  "Es un cuchillo con una hoja ancha y recia de un solo filo. Tiene una sencilla "
  "empuñadura de madera sin guarda, con la parte inferior ligeramente redondeada para "
  "acomodar los dedos. Resulta un utensilio muy dúctil en las tierras salvajes como "
  "herramienta o  arma secundaria.\n");
}