/*
DESCRIPCION : sandalias de cuero normales
FICHERO     : /d/akallab/comun/objeto/proteccion/sandalias_cuero.c
MODIFICACION: 30-11-98 [Angor@Simauria] Creacion
              04-12-98 [Nemesis@Simauria] Anyadido el material y el genero
--------------------------------------------------------------------------------
*/

inherit ARMOUR;
#include <properties.h>
#include <combat.h>

create(){
  if (::create()) return 1;
  SetStandard(AT_BOOTS,0, P_SIZE_MEDIUM, M_CUERO);
  SetShort("unas sandalias de cuero normales");
  SetLong(
    "Son unas sandalias de cuero del tipo mas corriente. Estan formadas por una\n"
    "delgada suela y una serie de tiras de cuero que cubren el pie. No son muy utiles\n"
    "en climas frios ya que al ser abiertas no aislan ni del frio ni del agua, pero\n"
    "son el calzado ideal para climas calidos.\n");

  SetIds(({"sandalias","sandalias de cuero"}));
}