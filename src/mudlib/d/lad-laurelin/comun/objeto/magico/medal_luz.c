/*
DESCRIPCION    : medallon magico de luz
FICHERO        : /d/lad-laurelin/comun/objeto/magico/medal_luz.c
CREACION       : Septiembre 2001
MODIFICACIONES : 28-Nov-01 [n] Retocado para que el medallón pierda sus
                               propiedades luminosas con los golpes
*/

inherit ARMOUR;
#include <properties.h>
#include <combat.h>

create() {
  ::create();
  SetIds(({"medallon","medallon luminoso","medallón","medallón luminoso"}));
  SetStandard(AT_AMULET, 0, P_SIZE_GENERIC, M_ORO);
  SetShort("un medallón luminoso");
  SetLong(
  "Es un colgante con una fina cadena de plata que sostiene la luminosa figura de un sol.\n");
  SetWeight(50);               //peso en gramos
  SetValue(100000);
  SetResetQuality(10);         //calidad estado al que puede llegar como máx
  SetMagic(1);
}

public varargs void NotifyEquip(object liv, object armour, int flags) {
  if (armour != TO) return;
    
   SetBright(40*QueryQuality()/100);  //Da bastante luz (si está bien)
   tell_object(TP,"El medallón brilla intensamente..\n");
   
   ::NotifyEquip(liv, armour, flags);
}

public varargs void NotifyUnequip(object liv, object armour, int flags) {
  if (armour != TO) return;
    
   SetBright(0);
   tell_object(TP,"El medallón pierde su luz.\n");
   
   ::NotifyUnequip(liv, armour, flags);
}

public void DegradeArmour ( mapping soaked, mapping damage, object weapon,
                            int success, int target) {
 int qual;
 ::DegradeArmour(soaked,damage,weapon,success,target);
 qual = QueryQuality();
 SetBright(40*qual/100);
}