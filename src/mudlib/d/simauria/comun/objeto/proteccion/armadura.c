/*   armadura.c
     Creado por : Nemesis
     Fecha 18-10-98
     Una armadura que estaba perdida en el jardin del castillo.
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
   TO->SetStandard(AT_GUANTES, 0, P_SIZE_GENERIC, M_CUERO);
   TO->SetShort("unos guantes de cuero");
   TO->SetLong("Son unos guantes de cuero sin dedos.\n");
   TO->AddId(({"guantes","guantes de cuero"}));
   TO->SetResetQuality(70);
   TO->SetQuality(65);
   TO->SetValue(10+random(5));
   return 1;
  }
  case 1: {
   TO->SetStandard(AT_CASCO, 0, P_SIZE_GENERIC, M_CUERO);
   TO->SetShort("un casco de cuero");
   TO->SetLong("Un casco agujereado. No debe tener mucho valor.\n");
   TO->AddId(({"casco","casco de cuero"}));
   TO->SetResetQuality(60);
   TO->SetQuality(50);
   TO->SetValue(5+random(8));
   return 1;
  }
  case 2: {
   TO->SetStandard(AT_AMULETO, 0, P_SIZE_GENERIC, M_ALUMINIO);
   TO->SetShort("un colgante de metal");
   TO->SetLong("Es un colgante con forma de aguila hecho de algún metal.\n");
   TO->AddId(({"colgante","amuleto"}));
   TO->SetResetQuality(90);
   TO->SetQuality(random(5)+random(10)+55);
   TO->SetWeight(25);
   TO->SetValue(QueryValue()/2);
   return 1;
  }
  case 3: {
   TO->SetStandard(AT_ANILLO, 0, P_SIZE_GENERIC, M_ACERO);
   TO->SetShort("un pequeño anillo");
   TO->SetLong("Un pequeño anillo dorado.\n");
   TO->AddId(({"anillo","anillo dorado"}));
   TO->SetResetQuality(90);
   TO->SetQuality(random(5)+random(10)+70);
   TO->SetValue(10);
   return 1;
  }
  case 4: {
   TO->SetStandard(AT_TUNICA, 0, P_SIZE_GENERIC, M_TELA);
   TO->SetShort("una sucia camisa");
   TO->SetLong("Una sucia camisa de una tela inidentificable.\n");
   TO->AddId(({"una sucia camisa","sucia camisa","camisa"}));
   TO->SetResetQuality(85);
   TO->SetQuality(55);
   TO->SetValue(15);
   return 1;
  }
 case 5: {
   TO->SetStandard(AT_PANTALONES, 0, P_SIZE_GENERIC, M_TELA);
   TO->SetShort("una falda larga");
   TO->SetLong("Es una larga falda de tela. Te preguntas quién la puede haber perdido...\n");
   TO->AddId(({"falda","falda larga"}));
   TO->SetResetQuality(85);
   TO->SetQuality(random(5)+random(10)+50);
   TO->SetValue(random(5)+5);
   return 1;
  }
 case 6: {
   TO->SetStandard(AT_CASCO, 0, P_SIZE_GENERIC, M_HIERRO);
   TO->SetShort("un casco de hojalata");
   TO->SetLong("Es un oxidado casco metálico.\n");
   TO->AddId(({"casco","viejo casco"}));
   TO->SetResetQuality(80);
   TO->SetQuality(random(5)+random(10)+45);
   TO->SetValue(20+random(5));
   return 1;
  }
 case 7: {
   TO->SetStandard(AT_ESCUDO, 1, P_SIZE_GENERIC, M_BRONCE);
   TO->SetShort("una rodela");
   TO->SetLong(
   "Un escudo redondo totalmente abollado. Tiene dibujado un círculo rojo.\n");
   TO->AddId(({"escudo","rodela"}));
   TO->SetResetQuality(70);
   TO->SetQuality(60);
   TO->SetValue(5+random(20));
   return 1;
  }
 case 8: {
   TO->SetStandard(AT_AMULETO, 0, P_SIZE_GENERIC, M_PLOMO);
   TO->SetLong("Es un amuleto con forma de espada.\n");
   TO->AddId(({"amuleto"}));
   TO->SetResetQuality(90);
   TO->SetQuality(random(5)+random(10)+70);
   TO->SetValue(random(25)+random(50));
   return 1;
  }
 case 9: {
   TO->SetStandard(AT_ANILLO, 0, P_SIZE_GENERIC, M_PLATA);
   TO->SetShort("una sortija de plata");
   TO->SetLong("Es una pequeña sortija de plata con perlas.\n");
   TO->AddId(({"sortija","anillo"}));
   TO->SetResetQuality(90);
   TO->SetQuality(random(5)+random(10)+70);
   TO->SetWeight(15);
   TO->Set(P_GENDER, GENERO_FEMENINO);
   return 1;
  }
 }
}


create() {
::create();
crear_objeto();
AddId(({"armadura"}));
}
