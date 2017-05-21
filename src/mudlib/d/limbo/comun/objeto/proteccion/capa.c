/*
DESCRIPCION  : una capa
FICHERO      : /d/limbo/comun/objeto/proteccion/capa.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
               22-10-98 [Nemesis@Simauria] Una capa es AT_CLOAK
               22-10-98 [Izet@Simauria] Vaaale, ya lo arreglo yooo...
               28-09-99 [Mirill@Simauria] Adapatación al nuevo combat.c
--------------------------------------------------------------------------------
*/

inherit ARMOUR;
#include <combat.h>;

#include <properties.h>;

create(){
  ::create();
  SetStandard(AT_CLOAK,0,P_SIZE_GENERIC,M_TELA);
  SetIds(({"capa"}));
  SetAds(({"de cuero","una"}));
  SetShort("una capa de cuero");
  SetLong("Es una capa larga de cuero, muy útil en climas fríos o húmedos.\n");
  SetValue(5);
  SetResetQuality(100);
  SetWeight(500);
  Set(P_NOSELL,1);
}
