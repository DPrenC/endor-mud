/* 
DESCRIPCION  : una camisa de tela
FICHERO      : /d/limbo/comun/objeto/proteccion/camisa.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
               04-12-98 [Nemesis@Simauria] Cambiado el P_GENDER a 1 (femenino)
--------------------------------------------------------------------------------
*/

inherit ARMOUR;
#include <combat.h>;
#include <properties.h>;

create(){
  if (::create()) return 1;
  SetStandard(AT_ARMOUR,0, P_SIZE_MEDIUM, M_TELA);
  SetShort("una camisa de tela");
  SetLong(
    "Es una camisa de manga larga de tela. El disenyo es sencillo, pero es bastante\n"+
    "comoda.\n");
  SetIds(({"camisa"}));
  SetAds(({"de tela","una"}));
  Set(P_NUMBER, NUMBER_SINGULAR);
  Set(P_GENDER, GENDER_FEMALE);
  SetResetQuality(100);
  SetSize(P_SIZE_MEDIUM);
  Set(P_MATERIAL,M_TELA);
  SetWeight(250);
  SetValue(250);
  //SetAC(0);
  //SetArmourType(AT_ARMOUR);
 }
