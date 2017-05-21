/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 02-12-99                |
 |               Ultima Modificacion.. 02-02-99                |
 |               Nyh lo toco el dia... 30-10-00                |
 |                                                             |
 *=============================================================*/
// 30-10-00 [Nyh] Pos lo he tocao pa qe sea chulo solo si lo usan
//		kisalas... y chupo pero menos si lo usan mujeres
//		y una gena en manos de los patosos hombres...

#include <gremios.h>
#include <combat.h>
#include "path.h"
#include <properties.h>
#include <materials.h>

inherit WEAPON;

#define WC_KISALA 6
#define WC_MUJER  4
#define WC_HOMBRE 2

create()
{
 ::create();
 if (!clonep()) return;
 // Vamos a considerarla un cuchillo
 SetStandard(WT_CUCHILLO,WC_HOMBRE,P_SIZE_MEDIUM,M_ACERO);
 SetWeight(700);
 SetShort("un doble abanico de acero");
 SetIds(({"abanico","doble abanico","doble abanico de acero","abanico de acero"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetNumberHands(1);
 SetLong("\
Se trata de dos abanicos cerrados que miden algo más de un palmo, fabricados\n\
de acero y que son extremadamente afilados, y por eso siempre han sido\n\
considerados como el arma perfecta por las kisalas.\n");
}

public varargs void NotifyUnequip(object liv, object weapon, int flags)
{
  if (weapon != TO) return;
  SetWC(WC_HOMBRE);
  ::NotifyUnequip(liv, weapon, flags);
}

public varargs void NotifyEquip(object liv, object weapon, int flags)
{
  if (weapon != TO) return;
    
  if (liv->QueryGuild()==GC_KISALAS)
  {
   SetWC(WC_KISALA);
   tell_object(liv, "Agarras fuertemente los abanicos y de un golpe seco los despliegas, te sientes más segura.\n");
  }
  else if (liv->QueryGender()==GENDER_FEMALE)
  {
   SetWC(WC_MUJER);
   tell_object(liv, "Coges los abanicos y los despliegas.\n");
  }
  else
  {
   SetWC(WC_HOMBRE);
   tell_object(liv, "¿Cómo se usarán estos abanicos...? Solo las mujeres lo saben.\n");
  }
	::NotifyEquip(liv, weapon, flags);
}
