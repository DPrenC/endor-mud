/*   arma.c
     Creado por : Nemesis
     Fecha 18-10-98
     Un arma que estaba perdida en el jardin del castillo.
*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

crear_objeto(str) {
int f,t;
 f=random(10);
 switch(f) {
  case 0: {
   TO->SetStandard(WT_CUCHILLO, 2, P_SIZE_MEDIUM, M_HIERRO);
   TO->SetShort("un viejo cuchillo");
   TO->SetLong("Es un viejo y oxidado cuchillo de monte.\n");
   TO->AddId(({"cuchillo","cuchillo de monte"}));
   TO->SetStandard(WT_CUCHILLO, 2, P_SIZE_MEDIUM, M_HIERRO);
   TO->SetResetQuality(70);
   TO->SetQuality(60);
   TO->SetValue(150+random(50));
   return 1;
  }
  case 1: {
   TO->SetStandard(WT_ESPADA, 2, P_SIZE_MEDIUM, M_HIERRO);
   TO->SetShort("una espada corta");
   TO->SetLong("Es una herrumbrosa espada corta.\n");
   TO->AddId(({"espada","espada corta"}));
   TO->SetResetQuality(70);
   TO->SetQuality(60);
   TO->SetValue(200+random(25));
   return 1;
  }
  case 2: {
   TO->SetStandard(WT_MAZA, random(2)+random(3)+1, P_SIZE_MEDIUM, M_MADERA);
   TO->SetShort("una maza de madera");
   TO->SetLong("Es una carcomida maza de madera.\n");
   TO->AddId(({"maza","maza de madera"}));
   TO->SetResetQuality(70);
   TO->SetQuality(random(5)+random(10)+45);
   TO->SetValue(45);
   return 1;
  }
  case 3: {
   TO->SetStandard(WT_HACHA, random(2)+random(3), P_SIZE_MEDIUM, M_HIERRO);
   TO->SetShort("un hacha de mano");
   TO->SetLong("Una vieja hacha de mano.\n");
   TO->AddId(({"hacha","hacha de mano"}));
   TO->SetResetQuality(85);
   TO->SetQuality(random(5)+random(10)+50);
   TO->SetValue(55);
   return 1;
  }
  case 4: {
   TO->SetStandard(WT_VARA, 1, P_SIZE_MEDIUM, M_MADERA);
   TO->SetWeaponType(WT_VARA);
   TO->SetShort("media lanza");
   TO->SetLong("Es el asta de una lanza. Ha perdido la punta.\n");
   TO->AddId(({"asta","lanza","media lanza","asta de una lanza"}));
   TO->SetNumberHands(1);
   TO->SetResetQuality(60+random(11));
   TO->SetQuality(50);
   TO->SetWeight(80);
   TO->SetValue(15);
   return 1;
  }
 case 5: {
   TO->SetStandard(WT_CADENA, 2, P_SIZE_MEDIUM, M_ACERO);
   TO->SetShort("una oxidada cadena");
   TO->SetLong("Es una cadena llena de oxido. Parece solida, aunque no demasiado.\n");
   TO->AddId(({"cadena","cadena oxidada"}));
   TO->SetResetQuality(80);
   TO->SetQuality(random(5)+random(10)+25);
   return 1;
  }
 case 6: {
   TO->SetStandard(WT_ESGRIMA, 2, P_SIZE_MEDIUM, M_HIERRO);
   TO->SetShort("un florete");
   TO->SetLong("Es un viejo florete. No parece muy dañino...\n");
   TO->AddId(({"florete","viejo florete"}));
   TO->SetResetQuality(90);
   TO->SetQuality(random(5)+random(10)+70);
   return 1;
  }
 case 7: {
   TO->SetStandard(WT_CUCHILLO, 1, P_SIZE_MEDIUM, M_BRONCE);
   TO->SetShort("una daga");
   TO->SetLong(
   "Es una vieja daga. Sin embargo, bajo la mugre brilla con reflejos dorados.\n");
   TO->AddId(({"cuchillo","daga"}));
   TO->SetDamageType(DT_PIERCE);
   TO->SetResetQuality(95);
   TO->SetQuality(70);
   TO->Set(P_GENDER, GENDER_FEMALE);
   return 1;
  }
 case 8: {
   TO->SetStandard(WT_MAZA, 1, P_SIZE_MEDIUM, M_MADERA);
   TO->SetShort("un bastón");
   TO->SetLong("Es un viejo bastón de madera.\n");
   TO->AddId(({"bastón","bastón de madera","baston","baston de madera"}));
   TO->SetResetQuality(75);
   TO->SetQuality(random(5)+random(10)+60);
   TO->Set(P_GENDER, GENDER_MALE);
   TO->SetValue(random(25)+50);
   return 1;
  }
 case 9: {
   TO->SetStandard(WT_MANOPLA, 2, P_SIZE_MEDIUM, M_ACERO);
   TO->SetShort("un gancho de carne");
   TO->SetLong("Es un gancho de los que usan en los mataderos.\n");
   TO->AddId(({"gancho","gancho de carne"}));
   TO->SetDamageType(DT_PIERCE);
   TO->SetResetQuality(90);
   TO->SetQuality(random(5)+random(10)+70);
   TO->SetWeight(75);
   TO->Set(P_GENDER, GENDER_MALE);
   TO->SetValue(30);
   return 1;
  }
 }
}


create() {
::create();
crear_objeto();
AddId(({"arma"}));
}
