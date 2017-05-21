/*
  armad_rnd.c
  (c) Nemesis@Simauria
  Descripcion: Una armadura aleatoria. Usar en herrerías y tiendas de _lujo_
               _NUNCA_ en tiendas cutres. Y lo mismo para los pnjs. Algunas
               de las posibilidades son bastante tochas.
*/


#include <combat.h>
#include <properties.h>
#include <materials.h>

inherit ARMOUR;

crear_objeto(str) {
int f,t,s;
string simbolo;
 s=random(21);
 switch(s) {
  case 0: {
   simbolo="una cruz de color rojo";
   break;
  }
  case 1: {
   simbolo="un dragón alado de color negro";
   break;
  }
  case 2: {
   simbolo="una espada de fuego sobre fondo azul";
   break;
  }
  case 3: {
   simbolo="un hacha partiendo en dos un rayo";
   break;
  }
  case 4: {
   simbolo="una calavera de orco y dos tibias cruzadas";
   break;
  }
  case 5: {
   simbolo="dos ángeles combatiendo con sus espadas";
   break;
  }
  case 6: {
   simbolo="una cola de escorpión";
   break;
  }
  case 7: {
   simbolo="seis 'X' de color rojo";
   break;
  }
  case 8: {
   simbolo="un sol y una luna";
   break;
  }
  case 9: {
   simbolo="una araña de color amarillo";
   break;
  }
  case 10: {
   simbolo="una calavera de dientes puntiagudos con\n"+" dos sables cruzados debajo";
   break;
  }
  case 11: {
   simbolo="una cabeza de unicornio";
   break;
  }
  case 12: {
   simbolo="una grotesca cabeza de trasgo";
   break;
  }
  case 13: {
   simbolo="la cara de una ninfa";
   break;
  }
  case 14: {
   simbolo="cinco círculos situados formando una X";
   break;
  }
  case 15: {
   simbolo="una cabeza de águila de color dorado";
   break;
  }
  case 16: {
   simbolo="un caballo encabritado";
   break;
  }
  case 17: {
   simbolo="una cabeza de toro de color rojo";
   break;
  }
  case 18: {
   simbolo="una rosa roja";
   break;
  }
  case 19: {
   simbolo="un pozo";
   break;
  }
  case 20: {
   simbolo="una media luna plateada";
   break;
  }

 }

 f=random(11);
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
   TO->SetLong("Un casco agujereado. No debe tener mucho valor.\n");
   TO->AddId(({"casco","casco de cuero"}));
   TO->SetResetQuality(75);
   TO->SetQuality(75);
   return 1;
  }
  case 2: {
   TO->SetStandard(AT_ARMOUR, 12, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("una coraza pesada");
   TO->SetLong("Es una sólida coraza de metal. "
                          "Está decorada con "+simbolo+".\n");
   TO->AddId(({"armadura","coraza","coraza pesada"}));
   TO->SetResetQuality(95);
   TO->SetQuality(95);
   return 1;
  }
  case 3: {
   TO->SetStandard(AT_ARMOUR, 9, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("una armadura imbricada");
   TO->SetLong("Una coraza de cuero reforzada con escamas de metal superpuestas. "
                          "Está decorada con "+simbolo+".\n");
   TO->AddId(({"armadura","coraza","armadura imbricada"}));
   TO->SetResetQuality(90);
   return 1;
  }
  case 4: {
   TO->SetStandard(AT_ARMOUR, 7, P_SIZE_GENERIC, M_CUERO);
   TO->SetShort("un cuirbolli");
   TO->SetLong("Una armadura de cuero que ha sido endurecida cociéndola en aceite hirviendo. "
                          "En el peto han dibujado "+simbolo+".\n");
   TO->AddId(({"coraza","cuirbolli","armadura"}));
   TO->SetResetQuality(95);
   TO->SetQuality(90);
   TO->Set(P_GENDER,GENERO_MASCULINO);
   return 1;
  }
 case 5: {
   TO->SetStandard(AT_GLOVES, 1, P_SIZE_GENERIC, M_HIERRO);
   TO->SetShort("unos guantes de malla");
   TO->SetLong("Unos guantes hechos de malla metálica.\n");
   TO->AddId(({"guantes de malla","guantes"}));
   TO->SetResetQuality(90);
   TO->SetQuality(90);
   return 1;
  }
 case 6: {
   TO->SetStandard(AT_HELMET, 3, P_SIZE_GENERIC, M_TITANIO);
   TO->SetShort("un tokwan de titanio");
   TO->SetLong("Un casco metálico con forma de cabeza de dragón. Parece particularmente duro.\n");
   TO->AddId(({"casco","tokwan"}));
   TO->SetResetQuality(95);
   return 1;
  }
 case 7: {
   TO->SetStandard(AT_ARMOUR, 2, P_SIZE_GENERIC, M_CUERO);
   TO->SetShort("un sayo");
   TO->SetLong("Una armadura de piel de lobo.\n");
   TO->AddId(({"armadura","sayo"}));
   TO->Set(P_GENDER, GENERO_MASCULINO);
   TO->SetResetQuality(90);
   TO->Set(P_GENDER, GENERO_MASCULINO);
   TO->SetQuality(85);
   return 1;
  }
 case 8: {
   TO->SetStandard(AT_AMULET, 0, P_SIZE_GENERIC, M_NINGUNO);
   TO->SetShort("un amuleto");
   TO->SetLong("Es un amuleto con forma de espada.\n");
   TO->AddId(({"amuleto"}));
   TO->SetMaterial("plomo");
   TO->SetResetQuality(90);
   TO->SetQuality(25+random(5)+random(10)+random(15));
   return 1;
  }
 case 9: {
   TO->SetStandard(AT_ARMOUR, 8, P_SIZE_GENERIC, M_CUERO);
   TO->SetShort("una coraza de cuero claveteado");
   TO->SetLong(
  "Una coraza de cuero con enormes clavos clavados en ella para darle solidez. "
  "Está decorada con el dibujo de "+simbolo+".\n");
   TO->AddId(({"coraza","armadura","coraza de cuero claveteado","coraza de cuero"}));
   TO->SetResetQuality(100);
   TO->SetQuality(95);
   return 1;
  }

case 10: {
   TO->SetStandard(AT_PANTALONES, 2, P_SIZE_GENERIC, M_CUERO);
   TO->SetShort("unas grebas de cuero");
   TO->SetLong(
  "Son unas grebas hechas de cuero endurecido. Sin duda no son nada espectacular, "
  "pero al menos son algo...\n");
   TO->AddId(({"grebas","armadura","grebas de cuero endurecido","grebas de cuero"}));
   TO->SetResetQuality(100);
   TO->SetQuality(95);
   return 1;
  }
 }
}


create() {
::create();
crear_objeto();
AddId(({"armadura"}));
}
