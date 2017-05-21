
/* alfanje.c
   Creado por : Nemesis@Simauria
   Descripcion : Un pequenyo regalito para los que consigan llegar al final del
                laberinto debajo de las mazmorras de Nandor.

*/


inherit WEAPON;
#include <combat.h>
#include <properties.h>
#include <materials.h>

create() {
  ::create();
  SetStandard(WT_ESGRIMA, 10, P_SIZE_GENERIC, M_ADAMANTIO);
  SetAds(({"un","ligero","afilado"}));
  AddId(({"alfanje","arma","espada"}));
  SetShort("un alfanje");
  SetLong(
"Es una ligera espada de hoja curva, muy estrecha en la base, pero bastante\n\
ancha en la punta. Su elaborada empuñadura, hecha de oro con piedras preciosas\n\
te hace pensar que es un arma digna de un rey.\n");
//SetWeight(1500);
  Set(P_GENDER,GENDER_MALE);
  SetQuality(85);
  SetResetQuality(85);
}
