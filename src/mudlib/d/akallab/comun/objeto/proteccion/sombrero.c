/*
DESCRIPCION  : un sombrero
FICHERO      : /d/limbo/comun/objeto/proteccion/sombrero.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
               04-12-98 [Nemesis@Simauria] Eliminados genero y numero y anyadido
	                                   el material.
--------------------------------------------------------------------------------
*/

inherit ARMOUR;
#include <combat.h>;
#include <properties.h>;

create(){
  ::create();
  SetStandard(AT_CAPUCHA, 1, P_SIZE_LARGE, M_TELA);
  SetShort("un sombrero de ala ancha");
  SetLong("Es un sombrero de ala ancha. Te protegera del sol y la lluvia.\n");
  SetIds(({"sombrero"}));
  SetAds(({"un"}));
}
