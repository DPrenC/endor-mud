/*   flor.c
     Creado por : Nemesis
     Fecha 19-10-98
     Una floresilla que te encuentras por ahi...
     Nota de Theuzifan : NO hace falta poner TO...
*/

#include <properties.h>

inherit THING;

crear_objeto(str) {
int f,t;
 f=random(15);
 switch(f) {
  case 0: {
   TO->SetLong("Un bello pensamiento.\n");
   TO->AddId(({"pensamiento"}));
   TO->SetSmell("Como huele un pensamiento?\n");
   return 1;
  }
  case 1: {
   TO->SetLong("Una hermosa orquidea.\n");
   TO->AddId(({"orquidea"}));
   TO->SetSmell("Tiene un olor suave y salvaje a la vez.\n");
   TO->Set(P_GENDER, GENDER_FEMALE);
  }
  case 2: {
   TO->SetLong("Una fragante violeta.\n");
   TO->AddId(({"violeta"}));
   TO->SetSmell("La violeta tiene un aroma muy dulce.\n");
   TO->Set(P_GENDER, GENDER_FEMALE);
   return 1;
  }
  case 3: {
   TO->SetLong("Una pequenya lila.\n");
   TO->AddId(({"lila"}));
   TO->SetSmell("A pesar de su pequenyez, su aroma es intenso.\n");
   TO->Set(P_GENDER, GENDER_FEMALE);
   return 1;
  }
  case 4: {
   TO->SetLong("Una rosa roja. Cuidado! No te pinches con las espinas!\n");
   TO->AddId(({"rosa","rosa roja"}));
   TO->SetSmell("Huele como una tipica rosa.\n");
   TO->Set(P_GENDER, GENDER_FEMALE);
   return 1;
  }
 case 5: {
   TO->SetLong("Una blanca gardenia.\n");
   TO->AddId(({"gardenia"}));
   TO->SetSmell("Mmm... Que aroma mas suave!\n");
   TO->Set(P_GENDER, GENDER_FEMALE);
   return 1;
  }
 case 6: {
   TO->SetLong("Una rosa blanca. Cuidado con las espinas!\n");
   TO->AddId(({"rosa","rosa blanca"}));
   TO->SetSmell("Blancas, rosas o rojas, todas huelen igual...\n");
   TO->Set(P_GENDER, GENDER_FEMALE);
   return 1;
  }
 case 7: {
   TO->SetLong("Un crisantemo de color blanco.\n");
   TO->AddId(({"crisantemo"}));
   TO->SetSmell("Tiene un aroma que te recuerda a un crisantemo.\n");
   TO->Set(P_GENDER, GENDER_FEMALE);
   return 1;
  }
 case 8: {
   TO->SetLong("Una blanca camelia.\n");
   TO->AddId(({"camelia"}));
   TO->SetSmell("Un aroma dulzon sale de sus petalos.\n");
   TO->Set(P_GENDER, GENDER_FEMALE);
   return 1;
  }
 case 9: {
   TO->SetLong("Un jacinto azul.\n");
   TO->AddId(({"jacinto"}));
   TO->SetSmell(
"Solo las rosas azules son peligrosas... Este solo huele bastante bien.\n");
   TO->Set(P_GENDER, GENDER_FEMALE);
   return 1;
  }
 default: {
   TO->SetLong("Una hortensia de color rosa palido.\n");
   TO->AddId(({"hortensia"}));
   TO->SetSmell("Huele como cualquier otra hortensia.\n");
   TO->Set(P_GENDER, GENDER_FEMALE);
   return 1;
  }
 }
}


create() {
::create();
SetShort("Una flor");
SetWeight(random(7));
SetValue(random(2)+random(3));
crear_objeto();
AddId(({"flor"}));
}
