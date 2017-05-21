/*
DESCRIPCION : zapatos de cuero normales
FICHERO     : /d/akallab/comun/objeto/proteccion/zapatos_cuero.c
MODIFICACION: 30-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

inherit ARMOUR;
#include <properties.h>
#include <combat.h>

create(){
  if (::create()) return 1;
  SetStandard(AT_BOOTS, 0, P_SIZE_MEDIUM, M_CUERO);
  SetShort("unos zapatos de cuero normales");
  SetLong(
    "Son unos zapatos de cuero del tipo mas corriente. Son cerrados, tienen poca\n"
    "suela y poseen unos cordones para atarlos.\n");
  SetIds(({"zapatos","zapatos de cuero"}));
}