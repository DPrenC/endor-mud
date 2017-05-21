/*
DESCRIPCION  : una camisa de tela
FICHERO      : /d/limbo/comun/objeto/proteccion/camisa.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
               22-10-98 [Nemesis@Simauria] Una camisa es AT_CLOAK
               28-09-99 [Mirill@Simauria] Adapatación al nuevo combat.c
               04-02-01 [Nyh@Simauria] Cambia AT_CLOAK por AT_MAIL, mas correcto
--------------------------------------------------------------------------------
*/

inherit ARMOUR;
#include <combat.h>;

#include <properties.h>;

create(){
  ::create();
  SetStandard(AT_MAIL,0,P_SIZE_MEDIUM,M_TELA);
  SetIds(({"camisa"}));
  SetAds(({"de tela","una"}));
  SetShort("una camisa de tela");
  SetLong(
     "Es una camisa de manga larga de tela. El diseño es sencillo, pero es bastante\n"
     "cómoda.\n");
  SetValue(5);
  SetResetQuality(100);
  SetWeight(250);
  Set(P_NOSELL,1);
}
