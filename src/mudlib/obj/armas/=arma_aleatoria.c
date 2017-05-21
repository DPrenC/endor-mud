
#include <mud.h>
#include <properties.h>
#include <combat.h>

inherit "/std/weapon";

crear_objeto(str) {
int f,t;
 f=random(10);
 switch(f) {
  case 0: {
   TO->SetStandard(WT_ESPADA, 2, P_SIZE_GENERIC, M_HIERRO);
   TO->SetShort("una vieja espada");
   TO->SetLong("Es una vieja espada corta de hoja recta.\n");
   TO->AddId(({"espada","espada corta"}));
   TO->SetResetQuality(80);
   TO->SetQuality(80);
   TO->SetValue(150+random(50));
   return 1;
  }
  case 1: {
   TO->SetStandard(WT_ESPADA, 5, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("una espada ancha");
   TO->SetLong("Es una poderosa espada ancha.\n");
   TO->AddId(({"espada","espada ancha"}));
   TO->SetResetQuality(85);
   TO->SetQuality(85);
   TO->SetValue(200+random(25));
   return 1;
  }
  case 2: {
   TO->SetStandard(WT_MAZA, random(2)+random(3)+random(2)+1, P_SIZE_GENERIC, M_MADERA);
   TO->SetShort("una maza de madera");
   TO->SetLong("Es una carcomida maza de madera.\n");
   TO->AddId(({"maza","maza de madera"}));
   TO->SetQuality(65+random(5)+random(10)+random(25));
   TO->SetWeight(1000+random(1000));
   TO->SetValue(45);
   return 1;
  }
  case 3: {
   TO->SetStandard(WT_HACHA, 2+random(2)+random(3), P_SIZE_GENERIC, M_HIERRO);
   TO->SetShort("un hacha de mano");
   TO->SetLong("Una vieja hacha de mano.\n");
   TO->AddId(({"hacha","hacha de mano"}));
   TO->SetResetQuality(75);
   TO->SetQuality(30+random(5)+random(10)+random(30));
   TO->SetValue(55);
   return 1;
  }
  case 4: {
   TO->SetStandard(WT_MAZA, 6, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("una maza de pinchos");
   TO->SetLong("Es una maza metalica con puntiagudos pinchos por toda ella.\n");
   TO->AddId(({"maza","maza de pinchos"}));
   TO->SetDamType(DT_SLASH);
   TO->SetResetQuality(85);
   TO->SetQuality(80);
   TO->SetValue(150);
   return 1;
  }
 case 5: {
   TO->SetStandard(WT_MANGUAL, 5, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("un mangual");
   TO->SetLong("Aunque la cadena esta llena de oxido, las tres colas estan en perfectas condiciones.\n");
   TO->AddId(({"mangual"}));
   TO->SetResetQuality(85);
   TO->SetQuality(75);
   TO->SetValue(100);
   return 1;
  }
 case 6: {
   TO->SetStandard(WT_HACHA, 11, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("un zaghnal");
   TO->SetLong("Es una poderosa hacha con dos pesadas hojas curvas en forma de cuchillo.\n");
   TO->AddId(({"zaghnal","hacha"}));
   TO->Set(P_GENDER, GENDER_MALE);
   TO->SetResetQuality(90);
   TO->SetQuality(90);
   return 1;
  }
 case 7: {
   TO->SetStandard(WT_MANGUAL, 10, P_SIZE_GENERIC, M_HIERRO);
   TO->SetShort("un mangual pesado");
   TO->SetLong("Es un pesado mangual.\n");
   TO->AddId(({"mangual"}));
   TO->SetResetQuality(80);
   TO->SetQuality(80);
   return 1;
  }
 case 8: {
   TO->SetStandard(WT_MAZA, 7, P_SIZE_GENERIC, M_NINGUNO);
   TO->SetShort("un plombee");
   TO->SetLong("Un poderoso mazo lastrado con plomo.\n");
   TO->AddId(({"plombee","mazo"}));
   TO->Set(P_MATERIAL,"plomo");
   TO->Set(P_GENDER, GENDER_MALE);
   TO->SetResetQuality(90);
   TO->SetQuality(90);
   return 1;
  }
 case 9: {
   TO->SetStandard(WT_ESPADA, 8, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("un yatagan");
   TO->SetLong("Una espada curva con la hoja muy afilada.\n");
   TO->AddId(({"yatagan","espada"}));
   TO->Set(P_GENDER, GENDER_MALE);
   TO->SetResetQuality(90);
   TO->SetQuality(85);
   return 1;
  }
 }
}


create() {
::create();
crear_objeto();
AddId(({"arma"}));
}
