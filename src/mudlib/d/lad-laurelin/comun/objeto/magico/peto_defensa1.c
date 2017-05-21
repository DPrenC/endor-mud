//Descripcion: Peto de defensa magico
//Creacion: Junio 2001
//Creador: Alura
// Modificaciones:


inherit ARMOUR;
#include "path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>

create()
{
  ::create();
  if (!clonep()) return;
  SetStandard(AT_ARMOUR, 7, P_SIZE_MEDIUM, M_HIERRO);
  SetShort("un peto especial de defensa");
  SetLong("Es un peto de defensa contra mazas.\n");
  SetIds(({"peto", "peto de defensa contra mazas"}));
  Set(P_GENDER, GENDER_MALE);
  Set(P_AP_PER_QP,200);
  AddDefence(DT_BLUDGEON, 10);
  AddDefence(DT_PIERCE, 5);
  AddDefence(DT_SLASH, -15);
  SetResetQuality(100);
  SetValue(1250000);
  SetMagic(1);
}

