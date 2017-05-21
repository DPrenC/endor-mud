/*
  amd_cutre.c
  (c) Nemesis@Simauria
  Descripcion:
  Una armadura aleatoria. En este caso, una armadura _cutre_ aleatoria.
  Útil para ponerla en tiendas de todo a 100 o para pnjs no demasiado
  potentes.
*/

#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

crear_objeto(str) {
int f,t;
 f=random(10);
 switch(f) {
  case 0: {
   TO->SetStandard(AT_GLOVES, 0, P_SIZE_GENERIC, M_CUERO);
   TO->SetShort("unos guantes de cuero");
   TO->SetLong("Son unos guantes de cuero sin dedos.\n");
   TO->AddId(({"guantes","guantes de cuero"}));
   TO->SetResetQuality(80);
   TO->SetQuality(75);
   return 1;
  }
  case 1: {
   TO->SetStandard(AT_HELMET, 0, P_SIZE_GENERIC, M_CUERO);
   TO->SetShort("un casco de cuero");
   TO->SetLong("Un casco agujereado. No parece tener mucho valor.\n");
   TO->AddId(({"casco","casco de cuero"}));
   TO->SetResetQuality(75);
   TO->SetQuality(75);
   return 1;
  }
  case 2: {
   TO->SetStandard(AT_ARMOUR, 3, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("una cota de mallas");
   TO->SetLong("Es una ligera cota de malla.\n");
   TO->AddId(({"armadura","cota","cota de mallas","cota de malla"}));
   TO->SetResetQuality(95);
   TO->SetQuality(95);
   return 1;
  }
  case 3: {
   TO->SetStandard(AT_ARMOUR, 2, P_SIZE_GENERIC, M_CUERO);
   TO->SetShort("una cota de cuero");
   TO->SetLong("Una cota hecha de láminas de cuero.\n");
   TO->AddId(({"armadura","cota","cota de cuero"}));
   TO->SetResetQuality(90);
   TO->SetQuality(85);
   return 1;
  }
  case 4: {
   TO->SetStandard(AT_ARMOUR, 0, P_SIZE_GENERIC, M_TELA);
   TO->SetShort("un escaupil");
   TO->SetLong("Una armadura hecha de algodón acolchado.\n");
   TO->AddId(({"coraza","escaupil","armadura"}));
   TO->SetResetQuality(95);
   TO->SetQuality(90);
   TO->Set(P_GENDER, GENERO_MASCULINO);
   return 1;
  }
 case 5: {
   TO->SetStandard(AT_GLOVES, 2, P_SIZE_GENERIC, M_HIERRO);
   TO->SetShort("unos guantes de malla");
   TO->SetLong("Unos guantes hechos de malla metálica.\n");
   TO->AddId(({"guantes de malla","guantes"}));
   TO->SetResetQuality(90);
   TO->SetQuality(80);
   return 1;
  }
 case 6: {
   TO->SetStandard(AT_HELMET, 1, P_SIZE_GENERIC, M_HIERRO);
   TO->SetShort("un kabuto");
   TO->SetLong("Un casco metálico. Está un poco oxidado.\n");
   TO->AddId(({"casco","kabuto"}));
   TO->SetResetQuality(95);
   TO->SetQuality(95);
   return 1;
  }
 case 7: {
   TO->SetStandard(AT_ARMOUR, 1, P_SIZE_GENERIC, M_CUERO);
   TO->SetShort("un sayo");
   TO->SetLong("Una armadura de piel de lobo.\n");
   TO->AddId(({"armadura","sayo"}));
   TO->SetResetQuality(90);
   TO->SetQuality(85);
   TO->Set(P_GENDER,GENERO_MASCULINO);
   return 1;
  }
 case 8: {
   TO->SetStandard(AT_AMULET, 0, P_SIZE_GENERIC, M_NINGUNO);
   TO->SetShort("un amuleto");
   TO->SetLong("Es un amuleto con forma de espada.\n");
   TO->AddId(({"amuleto"}));
   TO->SetMaterial("plomo");
   TO->SetResetQuality(90);
   TO->SetQuality(15+random(5)+random(10)+random(15));
   return 1;
  }
 case 9: {
   TO->SetStandard(AT_ARMOUR, 1, P_SIZE_GENERIC, M_TELA);
   TO->SetShort("un teghily");
   TO->SetLong("Un ropón de tela acolchada.\n");
   TO->AddId(({"ropon","armadura","teghily", "ropón"}));
   TO->SetResetQuality(100);
   TO->SetQuality(95);
   TO->Set(P_GENDER, GENERO_MASCULINO);
   return 1;
  }
 }
}


create() {
::create();
crear_objeto();
AddId(({"armadura"}));
}
