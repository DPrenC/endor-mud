/* 
DESCRIPCION  : unos pantalones de tela
FICHERO      : /d/limbo/comun/objeto/proteccion/camisa.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion.
               04-12-98 [Nemesis@Simauria] Anyadido el material
--------------------------------------------------------------------------------
*/

inherit ARMOUR;
#include <combat.h>;
#include <properties.h>;

create(){
  if (::create()) return 1;
  SetStandard(AT_PANTALONES, 0, P_SIZE_MEDIUM, M_TELA);
  SetShort("unos pantalones de tela");
  SetLong(
     "Son unos pantalones normales de tela. La tela no es especialmente suave, pero\n"+
     "parece lo bastante resistente para el uso diario.\n");
  SetIds(({"pantalon","pantalones"}));
  SetAds(({"de tela","unos","un"}));
}
