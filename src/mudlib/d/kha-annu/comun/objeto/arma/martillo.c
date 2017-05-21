//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*
//*   espag2.c                          *
//* Archivo de: Gorthem, El forjador    *
//* Email: jorcama@euibbs.upv.es        *
//* Basado en --------.c                *
//* Creacion: 12.05.98                  *
//* Modificacion: 02.11.98              *
//* Agradecimientos:                    *
//* Retocado por [Y] Yandros a 03.11.98 *
//* para hacer un martillo              *
//* [Nemesis] Anyadido el material      *
//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*/


#include "./path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>



inherit WEAPON;


create() {
  ::create();
  SetShort("un martillo de guerra");
  SetLong(
"Es un increible martillo de guerra a dos manos, con una maza reluciente y un\n"
"mango reforzado con cuero entrelazado para una mejor agarre. Parece bastate pesado.\n");
  SetIds( ({"martillo","martillo de guerra","martillo de yako"}) );
  SetAds( ({"un","el"}) );
  SetWC(7);
  SetWeaponType(WT_MAZA);
  SetDamType(DT_BLUDGEON);
  Set(P_MATERIAL,"metal");
  SetNumberHands(2);
  Set(P_GENDER,GENDER_MALE);
  SetWeight(18000);
  SetValue(5000);
  SetResetQuality(100);
  SetSize(P_SIZE_LARGE);
  SetSize(P_SIZE_LARGE);
}
