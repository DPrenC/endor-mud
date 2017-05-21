/*
 escudo_rnd.c
 (c) Nemesis@Simauria
 Descripcion: Un escudo aleatorio, que incluso cambia de símbolo cada vez.
 Puede servir para ponerlo en alguna tienda (con muuucha moderación) o bien
 para armar a los guardias de una ciudad.

*/

#include <combat.h>
#include <properties.h>

inherit ARMOUR;

crear_objeto(str) {
int t,s;
string simbolo;
 s=random(23);
 switch(s) {
  case 0: {
   simbolo="a una cruz de color rojo";
   break;
  }
  case 1: {
   simbolo="o un dragón alado de color negro";
   break;
  }
  case 2: {
   simbolo="a una espada de fuego sobre fondo azul";
   break;
  }
  case 3: {
   simbolo="a un hacha partiendo en dos un rayo";
   break;
  }
  case 4: {
   simbolo="a una calavera de orco y dos tibias cruzadas";
   break;
  }
  case 5: {
   simbolo="os dos angeles combatiendo con sus espadas";
   break;
  }
  case 6: {
   simbolo="a una cola de escorpión";
   break;
  }
  case 7: {
   simbolo="as seis 'X' de color rojo";
   break;
  }
  case 8: {
   simbolo="os un sol y una luna";
   break;
  }
  case 9: {
   simbolo="a una araña de color amarillo";
   break;
  }
  case 10: {
   simbolo="a una calavera de dientes puntiagudos con dos sables cruzados debajo";
   break;
  }
  case 11: {
   simbolo="a una cabeza de unicornio";
   break;
  }
  case 12: {
   simbolo="a una grotesca cabeza de trasgo";
   break;
  }
  case 13: {
   simbolo="a una ninfa saliendo de las aguas";
   break;
  }
  case 14: {
   simbolo="os cinco círculos situados en forma de X";
   break;
  }
  case 15: {
   simbolo="as unas extrañas runas";
   break;
  }
  case 16: {
   simbolo="o un caballo encabritado negro sobre campo amarillo";
   break;
  }
  case 17: {
   simbolo="a una cabeza de toro";
   break;
  }
  case 18: {
   simbolo="a una espada plateada";
   break;
  }
  case 19: {
   simbolo="o un pozo";
   break;
  }
  case 20: {
   simbolo="a una rosa y la inscripción:\n'Todas tienen espinas'";
   break;
  }
  case 21: {
   simbolo="a una garra sosteniendo un hacha";
   break;
  }
  case 22: {
   simbolo="a una serpiente enroscada alrededor de un árbol";
   break;
  }

 }


 t=random(10);
 switch(t) {
  case 0: {
   TO->SetStandard(AT_SHIELD, 1, P_SIZE_GENERIC, M_MADERA);
   TO->SetShort("un broquel de madera");
   TO->SetLong(
   "Un pequeño escudo redondo. "
   "Tiene dibujad"+simbolo+".\n");
   TO->AddId(({"broquel","broquel de madera"}));
   TO->SetNumberHands(1);
   TO->SetResetQuality(90);
   TO->SetQuality(90);
   return 1;
  }
  case 1: {
   TO->SetStandard(AT_SHIELD, 2, P_SIZE_GENERIC, M_BRONCE);
   TO->SetShort("una rodela abollada");
   TO->SetLong(
   "Un escudo metálico. Tiene dibujad"+simbolo+". "
   "A pesar de estar abollada, aún parece sólida.\n");
   TO->AddId(({"rodela","rodela abollada"}));
   TO->SetNumberHands(1);
   TO->SetResetQuality(95);
   TO->SetQuality(90);
   TO->SetWeight(1000);
   TO->Set(P_GENDER, GENERO_FEMENINO);
   return 1;
  }
  case 2: {
   TO->SetStandard(AT_SHIELD, 4, P_SIZE_GENERIC, M_HIERRO);
   TO->SetShort("un sólido talvas");
   TO->SetLong(
   "Un enorme escudo de metal. "
   "Tiene dibujad"+simbolo+".\n");
   TO->AddId(({"talvas","solido talvas","sólido talvas"}));
   TO->SetNumberHands(1);
   TO->SetResetQuality(95);
   TO->SetQuality(95);
   return 1;
  }
  case 3: {
   TO->SetStandard(AT_SHIELD, 3, P_SIZE_GENERIC, M_MADERA);
   TO->SetShort("un pesado tarian");
   TO->SetLong(
   "Un pequeño pero pesado escudo de madera. "
   "Tiene dibujad"+simbolo+".\n");
   TO->AddId(({"tarian","pesado tarian"}));
   TO->SetResetQuality(90);
   TO->SetQuality(85);
   return 1;
  }
  case 4: {
   TO->SetStandard(AT_SHIELD, 6, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("un pavés");
   TO->SetLong(
   "Un escudo de metal. Cubre el torso y parte de la cintura y tiene\n"
   "dibujad"+simbolo+".\n");
   TO->AddId(({"paves","pavés"}));
   TO->SetNumberHands(1);
   TO->SetResetQuality(95);
   TO->SetQuality(90);
   return 1;
  }
 case 5: {
   TO->SetStandard(AT_SHIELD, 3, P_SIZE_GENERIC, M_CUERO);
   TO->SetShort("un escudo de cuero");
   TO->SetLong(
   "Un ligero escudo hecho de varias capas de cuero y bronce. "
   "Tiene dibujad"+simbolo+".\n");
   TO->AddId(({"escudo de cuero"}));
   TO->SetResetQuality(90);
   TO->SetQuality(90);
   return 1;
  }
 case 6: {
   TO->SetStandard(AT_SHIELD, 6, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("una tarja");
   TO->SetLong(
   "Un enorme escudo de metal. Parece muy sólido. "
   "Tiene dibujad"+simbolo+".\n");
   TO->AddId(({"tarja"}));
   TO->SetNumberHands(1);
   TO->SetResetQuality(95);
   TO->SetQuality(95);
   TO->Set(P_GENDER, GENERO_FEMENINO);
   return 1;
  }
 case 7: {
   TO->SetStandard(AT_SHIELD, 5, P_SIZE_GENERIC, M_HIERRO);
   TO->SetShort("un baluse");
   TO->SetLong(
   "Un escudo ovalado con un pesado listón saliente. "
   "Tiene dibujad"+simbolo+".\n");
   TO->AddId(({"baluse"}));
   TO->SetNumberHands(1);
   TO->SetResetQuality(90);
   TO->SetQuality(85);
   return 1;
  }
 case 8: {
   TO->SetStandard(AT_SHIELD, 5, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("un cetra");
   TO->SetLong(
   "Un escudo redondo de casi un metro de diámetro. "
   "Tiene dibujad"+simbolo+".\n");
   TO->AddId(({"cetra"}));
   TO->SetNumberHands(1);
   TO->SetResetQuality(90);
   TO->SetQuality(90);
   return 1;
  }
 case 9: {
   TO->SetStandard(AT_SHIELD, 3, P_SIZE_GENERIC, M_ALUMINIO);
   TO->SetShort("un pelta");
   TO->SetLong(
   "Un ligero escudo redondo. "
   "Tiene dibujad"+simbolo+".\n");
   TO->AddId(({"pelta"}));
   TO->SetResetQuality(100);
   TO->SetQuality(95);
   return 1;
  }
 }
}


create() {
::create();
crear_objeto();
}
