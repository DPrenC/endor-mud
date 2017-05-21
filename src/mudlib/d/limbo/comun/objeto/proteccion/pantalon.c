/*
DESCRIPCION  : unos pantalones de tela
FICHERO      : /d/limbo/comun/objeto/proteccion/camisa.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
               22-10-98 [Izet@Simauria] Como diria Neme: unos pantalones
                                        son AT_TROUSERS, pero ya lo arreglo
                                        yo.
               28-09-99 [Mirill@Simauria] Adapatación al nuevo combat.c
--------------------------------------------------------------------------------
*/

inherit ARMOUR;
#include <combat.h>;

#include <properties.h>;

create(){
  ::create();
  SetStandard(AT_TROUSERS,0,P_SIZE_GENERIC,M_TELA);
  SetIds(({"pantalón","pantalon","pantalones"}));
  SetAds(({"de tela","unos","un"}));
  SetShort("unos pantalones de tela");
  SetLong(
     "Son unos pantalones normales de tela. La tela no es especialmente suave, pero\n"
     "parece lo bastante resistente para el uso diario.\n");
  SetValue(5);
  SetResetQuality(100);
  Set(P_NUMBER, NUMBER_PLURAL);
  SetWeight(500);
  Set(P_NOSELL,1);
}
