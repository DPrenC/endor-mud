/*
DESCRIPCION    : diadema que da resistencia a los ataques mentales
FICHERO        : /d/lad-laurelin/comun/objeto/magico/diadema.c
CREACION       : Junio 2001
*/

inherit ARMOUR;
#include <properties.h>
#include <combat.h>

create() {
  ::create();
  SetAds(({"una","azul"}));
  SetIds(({"diadema"}));
  SetStandard(AT_TIARA, 1, P_SIZE_LARGE, M_PIEDRA);
  SetShort("una diadema");
  SetLong(
  "Es un sencillo aro pulido de color azul que parece más decorativo que otra\n"
  "cosa. Esta diadema la usaban los clérigos para protegerse de los ataques\n"
  "mentales de los vampiros.\n");
  SetWeight(50);                        //peso en gramos
  SetValue(5000);
  SetArmourType(AT_HELMET);
  SetResetQuality(90);         //calidad estado en el que esta 0-100
  SetMagic(1);
  }

public varargs void NotifyEquip(object liv, object armour, int flags) {
  if (armour != TO) return;
    
   liv->AddResistance(12,20);
   
   ::NotifyEquip(liv, armour, flags);
}

public varargs void NotifyUnequip(object liv, object armour, int flags) {
  if (armour != TO) return;
    
   liv->AddResistance(12,-20);
   
   ::NotifyUnequip(liv, armour, flags);
}
