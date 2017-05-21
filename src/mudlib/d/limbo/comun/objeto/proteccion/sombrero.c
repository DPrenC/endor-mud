/*
DESCRIPCION  : un sombrero
FICHERO      : /d/limbo/comun/objeto/proteccion/sombrero.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
               28-09-99 [Mirill@Simauria] Adapatación al nuevo combat.c
--------------------------------------------------------------------------------
*/

inherit ARMOUR;
#include <combat.h>;

#include <properties.h>;

create(){
  ::create();
  SetStandard(AT_HELMET,0,P_SIZE_GENERIC,M_TELA);
  SetIds(({"sombrero"}));
  SetAds(({"fieltro","un"}));
  SetShort("un sombrero de ala ancha negro");
  SetLong("Es un sombrero de ala ancha de color negro. Te protegerá del sol y la lluvia.\n");
  SetValue(5);
  SetResetQuality(100);
  SetWeight(100);
  Set(P_NOSELL,1);
}
