/* 
DESCRIPCION  : un sombrero
FICHERO      : /d/limbo/comun/objeto/proteccion/capa.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
               04-12-98 [Nemesis@Simauria] Cambiado el P_GENDER a 1 (femenino)
	                                   Una capa es AT_CLOAK, hazme caso!
--------------------------------------------------------------------------------
*/

inherit ARMOUR;
#include <combat.h>;
#include <properties.h>;

create(){
  if (::create()) return 1;
  SetStandard(AT_MANTO, 1, P_SIZE_LARGE, M_CUERO);
  SetShort("una capa de cuero");
  SetLong("Es una capa larga de cuero, muy util en climas frios o humedos.\n");
  SetIds(({"capa"}));
  SetAds(({"de cuero","una"}));
  Set(P_NUMBER, NUMBER_SINGULAR);
  Set(P_GENDER, GENDER_FEMALE);
  Set(P_MATERIAL,M_CUERO);
  SetResetQuality(100);
  SetSize(P_SIZE_MEDIUM);
  SetWeight(500);
  SetValue(300);
  //SetAC(0);
  //SetArmourType(AT_ARMOUR);
}
