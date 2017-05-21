/*
  arma_rnd.c
  (c) Nemesis@Simauria

  Arma aleatoria para uso de las tiendas, pnjs,...
  NOTA: No usar al tuntún. En principio, con usarla en una tienda por zona
        vale. Otro posible uso es ponerla como arma de pnjs de algún dungeon.

*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

crear_objeto(str) {
int f,t;
 f=random(16);
 switch(f) {
  case 0: {
   TO->SetStandard(WT_ESPADA, 2, P_SIZE_GENERIC, M_HIERRO);
   TO->SetShort("una vieja espada");
   TO->SetLong("Es una vieja espada corta de hoja recta.\n");
   TO->AddId(({"espada","espada corta"}));
   TO->SetResetQuality(80);
   TO->SetQuality(80);
   return 1;
  }
  case 1: {
   TO->SetStandard(WT_ESPADA, 5, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("una espada ancha");
   TO->SetLong("Es una poderosa espada ancha.\n");
   TO->AddId(({"espada","espada ancha"}));
   TO->SetResetQuality(85);
   TO->SetQuality(85);
   return 1;
  }
  case 2: {
   TO->SetStandard(WT_MAZA, random(3)+random(2)+1, P_SIZE_GENERIC, M_MADERA);
   TO->SetShort("una maza de madera");
   TO->SetLong("Es una carcomida maza de madera.\n");
   TO->AddId(({"maza","maza de madera"}));
   TO->SetResetQuality(85);
   TO->SetQuality(65+random(5)+random(10)+random(25));
   return 1;
  }

  case 3: {
   TO->SetStandard(WT_HACHA, 2+random(3), P_SIZE_GENERIC, M_HIERRO);
   TO->SetShort("un hacha de mano");
   TO->SetLong("Una vieja hacha de mano.\n");
   TO->AddId(({"hacha","hacha de mano"}));
   TO->SetResetQuality(80);
   TO->SetQuality(30+random(5)+random(10)+random(30));
   return 1;
  }
  case 4: {
   TO->SetStandard(WT_MAZA, 6, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("una maza de pinchos");
   TO->SetLong("Es una maza metálica con puntiagudos pinchos por toda ella.\n");
   TO->AddId(({"maza de pinchos"}));
   TO->SetDamageType(DT_SLASH);
   TO->SetQuality(90);
   return 1;
  }
 case 5: {
   TO->SetStandard(WT_MANGUAL, 5, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("un mangual");
   TO->SetLong("Aunque la cadena esta llena de óxido, las tres colas están en perfectas condiciones.\n");
   TO->AddId(({"mangual"}));
   TO->SetResetQuality(85);
   TO->SetQuality(75);
   return 1;
  }
 case 6: {
   TO->SetStandard(WT_HACHA, 11, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("un zaghnal");
   TO->SetLong("Es una poderosa hacha con dos pesadas hojas curvas en forma de cuchillo.\n");
   TO->AddId(({"zaghnal","hacha"}));
   TO->Set(P_GENDER,GENERO_MASCULINO);
   TO->SetResetQuality(90);
   TO->SetQuality(90);
   return 1;
  }
 case 7: {
   TO->SetStandard(WT_MANGUAL, 10, P_SIZE_GENERIC, M_HIERRO);
   TO->SetShort("un mangual pesado");
   TO->SetLong("Es un pesado mangual.\n");
   TO->AddId(({"mangual"}));
   TO->SetNumberHands(2);
   TO->SetDamageType(DT_SLASH);
   TO->SetResetQuality(80);
   return 1;
  }
 case 8: {
   TO->SetStandard(WT_MAZA, 7, P_SIZE_GENERIC, M_NINGUNO);
   TO->SetShort("un plombee");
   TO->SetLong("Una pesada maza lastrada con plomo.\n");
   TO->AddId(({"plombee","mazo"}));
   TO->SetMaterial("plomo");
   TO->Set(P_GENDER,GENERO_MASCULINO);
   TO->SetResetQuality(90);
   TO->SetQuality(90);
   return 1;
  }
 case 9: {
   TO->SetStandard(WT_ESPADA, 8, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("un yatagán");
   TO->SetLong("Una espada curva con la hoja muy afilada.\n");
   TO->AddId(({"yatagán","espada","yatagan"}));
   TO->Set(P_GENDER,GENERO_MASCULINO);
   TO->SetResetQuality(90);
   TO->SetQuality(85);
   return 1;
  }
 case 10: {
   TO->SetStandard(WT_CUCHILLO, 2, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("un kriss");
   TO->SetLong("Un cuchillo de hoja larga y curvada.\n");
   TO->AddId(({"kriss","cuchillo"}));
   TO->Set(P_GENDER,GENERO_MASCULINO);
   TO->SetResetQuality(90);
   TO->SetQuality(85);
   return 1;
  }
 case 11: {
   TO->SetStandard(WT_LANZA, 4, P_SIZE_GENERIC, M_HIERRO);
   TO->SetShort("un arpón");
   TO->SetLong("Un temible arpón de punta dentada. Parece muy peligroso.\n");
   TO->AddId(({"arpón","lanza","arpon"}));
   TO->Set(P_GENDER,GENERO_MASCULINO);
   TO->SetResetQuality(90);
   TO->SetQuality(85);
   return 1;
  }

 case 12: {
   TO->SetStandard(WT_VARA, 3, P_SIZE_GENERIC, M_MADERA);
   TO->SetShort("una vara larga");
   TO->SetLong("Una larga vara de madera. Un arma simple, pero efectiva.\n");
   TO->AddId(({"vara","vara larga"}));
   TO->SetResetQuality(90);
   TO->SetQuality(85);
   return 1;
  }

 case 13: {
   TO->SetStandard(WT_MANOPLA, 4, P_SIZE_GENERIC, M_HIERRO);
   TO->SetShort("un garfio");
   TO->SetLong("Parece un gancho de carnicero, pero se engancha a la mano. "
               "Sin duda fue útil para algún pirata, aunque ahora está algo oxidado.\n");
   TO->AddId(({"garfio","gancho", "garfio pirata"}));
   TO->Set(P_GENDER,GENERO_MASCULINO);
   TO->SetResetQuality(80);
   TO->SetQuality(75);
   return 1;
  }

  case 14: {
   TO->SetStandard(WT_ESGRIMA, 5, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("un lujoso florete");
   TO->SetLong("Es un florete de hoja larga y punta afilada. La hoja brilla con un reflejo "
                         "azulado y la guarda está guarnecida de piedras preciosas.\n");
   TO->AddId(({"florete","lujoso florete"}));
   TO->SetNumberHands(1);
   TO->Set(P_GENDER,GENERO_MASCULINO);
   TO->SetValue(QueryValue()*3);
   TO->SetResetQuality(95);
   TO->SetQuality(95);
   return 1;
  }

   case 15: {
   TO->SetStandard(WT_ALABARDA, 8, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("una alabarda de guardia");
   TO->SetLong("Es una alabarda como las que usan los guardias. Tiene "
                          "punta de lanza y una\nhoja parecida a la de un hacha "
                          "en uno de los laterales del asta.\n");
   TO->AddId(({"alabarda","alabarda de guardia"}));
   TO->SetResetQuality(95);
   TO->SetQuality(95);
   return 1;
  }

 }
}


create() {
::create();
crear_objeto();
AddId(({"arma"}));
}
