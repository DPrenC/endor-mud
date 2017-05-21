/*   raro.c
     Creado por : Nemesis
     Fecha 18-10-98
     Un objeto muy raro que estaba perdido en el jardin del castillo.
*/

#include <properties.h>

inherit THING;

crear_objeto(str) {
int f,t;
 f=random(10);
 switch(f) {
  case 0: {
   TO->SetShort("una cuenta cuadrada");
   TO->SetLong("Una cuenta cuadrada que una vez pertenecio a un collar.\n");
   TO->AddId(({"cuenta","cuenta cuadrada"}));
   TO->SetWeight(25);
   TO->SetValue(5);
   return 1;
  }
  case 1: {
   TO->SetShort("una cuenta cuadrada");
   TO->SetLong("Una cuenta cuadrada que una vez pertenecio a un collar.\n");
   TO->AddId(({"cuenta","cuenta cuadrada"}));
   TO->SetWeight(25);
   TO->SetValue(5);
  }
  case 2: {
   TO->SetShort("una cuenta redonda");
   TO->SetLong("Una cuenta redonda que una vez pertenecio a un collar.\n");
   TO->AddId(({"cuenta","cuenta redonda"}));
   TO->SetWeight(25);
   TO->SetValue(5);
   return 1;
  }
  case 3: {
   TO->SetShort("una cuenta de cristal");
   TO->SetLong("Una cuenta de cristal que una vez pertenecio a un collar.\n");
   TO->AddId(({"cuenta","cuenta de cristal"}));
   TO->SetWeight(25);
   TO->SetValue(5);
   return 1;
  }
  case 4: {
   TO->SetShort("una piedra preciosa");
   TO->SetLong("Es un opalo resinoso. Una piedra de color amarillento con un brillo ceroso.\n");
   TO->AddId(({"piedra","piedra preciosa","opalo","opalo resinoso"}));
   TO->SetWeight(25);
   TO->Set(P_GENDER, GENDER_FEMALE);
   TO->SetValue(500);
   return 1;
  }
 case 5: {
   TO->SetShort("un eslabon oxidado");
   TO->SetLong("Seguramente alguna vez pertenecio a una cadena.\n");
   TO->AddId(({"eslabon","eslabon oxidado"}));
   TO->SetWeight(40);
   TO->Set(P_GENDER, GENDER_FEMALE);
   TO->SetValue(1);
   return 1;
  }
 case 6: {
   TO->SetShort("una piedra preciosa");
   TO->SetLong("Una turquesa. Es de color azul con pintas negras.\n");
   TO->AddId(({"piedra","piedra preciosa","turquesa"}));
   TO->SetWeight(25);
   TO->Set(P_GENDER, GENDER_FEMALE);
   TO->SetValue(200);
   return 1;
  }
 case 7: {
   TO->SetShort("un trozo de vidrio");
   TO->SetLong("Un trozo de vidrio rojo. Alguna vez debio formar parte de una ventana.\n");
   TO->AddId(({"trozo de vidrio rojo","trozo de vidrio","vidrio","vidrio rojo"}));
   TO->SetWeight(8);
   TO->SetValue(1);
   return 1;
  }
 case 8: {
   TO->SetShort("un engranaje");
   TO->SetLong("Una rueda dentada. Te preguntas que clase de maquina lo perdio...\n");
   TO->AddId(({"engranaje","rueda","rueda dentada"}));
   TO->SetWeight(100);
   TO->SetValue(10);
   return 1;
  }
 case 9: {
   TO->SetShort("un guijarro curioso");
   TO->SetLong("Tiene una forma muy peculiar, que le hace parecer una cara.\n");
   TO->AddId(({"guijarro","piedra","guijarro curioso"}));
   TO->SetWeight(50);
   TO->SetValue(1);
   return 1;
  }
 }
}


create() {
::create();
crear_objeto();
AddId(({"objeto"}));
}
