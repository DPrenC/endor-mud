/*   arma1.c
     Creado por : Nemesis
     Fecha: 28-Jul-01
	 Descripción: Arma para los kobolds normalillos...
                  Los kobolds normalillos no llevan armas demasiado
                  buenas: básicamente cuchillos, lanzas y mazas.
                  La mayoría de las armas son no metálicas, pero
                  también las hay metálicas.
*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

crear_objeto() {
int f,t;
 f=random(10);
 switch(f) {
  case 0: {
   TO->SetStandard(WT_CUCHILLO, 2, P_SIZE_SMALL, M_HIERRO);
   TO->SetShort("un viejo cuchillo");
   TO->SetLong("Es un viejo y oxidado cuchillo de monte.\n");
   TO->AddId(({"cuchillo","cuchillo de monte"}));
   TO->SetResetQuality(90);
   TO->SetQuality(60+random(30));
   return 1;
  }
  case 1: {
   TO->SetStandard(WT_CUCHILLO, 3, P_SIZE_SMALL, M_HIERRO);
   TO->SetShort("un cuchillo largo");
   TO->SetLong("Es un sucio cuchillo de hoja larga y negra.\n");
   TO->AddId(({"cuchillo","cuchillo largo"}));
   TO->SetResetQuality(95);
   TO->SetQuality(65+random(30));
   return 1;
  }
  case 2: {
   TO->SetStandard(WT_MAZA, 2, P_SIZE_SMALL, M_PIEDRA);
   TO->SetShort("una maza de piedra");
   TO->SetLong("Un pedrusco afilado enganchado a un palo mediante cuerdas.\n");
   TO->AddId(({"maza","maza de piedra"}));
   TO->SetResetQuality(85);
   TO->SetQuality(60+random(25));
   return 1;
  }
  case 3: {
   TO->SetStandard(WT_LANZA, 2, P_SIZE_SMALL, M_MADERA);
   TO->SetShort("una lanza de madera");
   TO->SetLong("Una simple rama toscamente afilada para que pinche.\n");
   TO->AddId(({"lanza","rama","lanza de madera"}));
   TO->SetResetQuality(90);
   TO->SetQuality(80+random(10));
   return 1;
  }
  case 4: {
   TO->SetStandard(WT_VARA, 1, P_SIZE_SMALL, M_MADERA);
   TO->SetWeaponType(WT_VARA);
   TO->SetShort("media lanza");
   TO->SetLong("Es el asta de una lanza. Ha perdido la punta.\n");
   TO->AddId(({"asta","lanza","media lanza","asta de una lanza"}));
   TO->SetNumberHands(1);
   TO->SetResetQuality(75);
   TO->SetQuality(60+random(15));
   TO->SetWeight(TO->QueryWeight()/2);
   return 1;
  }
 case 5: {
   TO->SetStandard(WT_CADENA, 4, P_SIZE_SMALL, M_ACERO);
   TO->SetShort("una oxidada cadena");
   TO->SetLong("Es una herrumbrosa cadena. Parece sólida, aunque no demasiado.\n");
   TO->AddId(({"cadena","cadena oxidada","herrumbrosa cadena"}));
   TO->SetResetQuality(80);
   TO->SetQuality(50+random(30));
   return 1;
  }
 case 6: {
   TO->SetStandard(WT_LANZA, 3, P_SIZE_SMALL, M_HIERRO);
   TO->SetShort("una horquilla");
   TO->SetLong("Una horquilla como las que se usan para remover la paja.\n");
   TO->AddId(({"horquilla"}));
   TO->SetResetQuality(70);
   TO->SetQuality(50+random(20));
   return 1;
  }
 case 7: {
   TO->SetStandard(WT_CUCHILLO, 1, P_SIZE_SMALL, M_BRONCE);
   TO->SetShort("una daga");
   TO->SetLong(
   "Es una vieja daga. Sin embargo, bajo la mugre brilla con reflejos dorados.\n");
   TO->AddId(({"cuchillo","daga"}));
   TO->Set(P_GENDER, GENDER_FEMALE);
   TO->SetDamageType(DT_PIERCE);
   TO->SetResetQuality(75);
   TO->SetQuality(60+random(15));
   return 1;
  }
 case 8: {
   TO->SetStandard(WT_MAZA, 2, P_SIZE_SMALL, M_HUESO);
   TO->SetShort("una porra de hueso");
   TO->SetLong("La cadera de algún animal grande convertida en arma contundente.\n");
   TO->AddId(({"porra","porra de hueso","cadera","fémur"}));
   TO->SetResetQuality(75);
   TO->SetQuality(75);
   return 1;
  }
 case 9: {
   TO->SetStandard(WT_ESPADA, 4, P_SIZE_SMALL, M_ACERO);
   TO->SetShort("una espada rota");
   TO->SetLong(
"Es una vieja espada corta partida por la mitad, que ha sido toscamente\n"
"reafilada para darle punta. A pesar de todo, parece peligrosa.\n");
   TO->AddId(({"espada","espada corta","media espada","espada corta"}));
   TO->SetDamageType(DT_PIERCE);
   TO->SetResetQuality(70);
   TO->SetQuality(60+random(10));
   TO->SetWeight(TO->QueryWeight()/2);
   return 1;
  }
 }
}


create() {
 ::create();
 crear_objeto();
 AddId(({"arma"}));
 // Para que no merezca la pena acumularlos, el valor de estos objetos será
 // el mínimo, aunque ya sabemos que los players son, en general, bastante
 // raritos... De todas formas, si se pasan, les "implantaré" las armas y
 // a los kobolds y arreglao...
 SetValue(random(3));
}
