/*   arma_guardias.c
     Creado por : Nemesis
     Fecha: 28-Jul-01
	 Descripción: Arma de dos manos para los guardias kobold.
                  Aunque no llevan armas poderosas, sí son
                  relativamente buenas y están bastante bien
                  cuidadas.				
*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

crear_objeto(str) {
int f,t;
 f=random(10);
 switch(f) {
  case 0: {
   TO->SetStandard(WT_ESPADA, 6, P_SIZE_SMALL, M_HIERRO);
   TO->SetShort("un cladibas");
   TO->SetLong("Una espada pesada con una larga hoja, algo gastada.\n");
   TO->AddId(({"espada","cladibas"}));
   TO->Set(P_GENDER,GENERO_MASCULINO);
   return 1;
  }
  case 1: {
   TO->SetStandard(WT_ALABARDA, 5, P_SIZE_SMALL, M_ACERO);
   TO->SetShort("una glaive");
   TO->SetLong(
"Una alabarda de hoja ancha, con el filo curvado hacia atrás cerca\n"
"de la punta.\n");
   TO->AddId(({"alabarda","glaive"}));
   return 1;
  }
  case 2: {
   TO->SetStandard(WT_LANZA, 5, P_SIZE_SMALL, M_BRONCE);
   TO->SetShort("una larga pica");
   TO->SetLong("Una larga pica con punta de bronce.\n");
   TO->AddId(({"lanza","pica"}));
   return 1;
  }
  case 3: {
   TO->SetStandard(WT_HACHA, 7, P_SIZE_SMALL, M_HIERRO);
   TO->SetShort("una pesada dolores");
   TO->SetLong("Una pesada hacha de guerra con hoja redondeada.\n");
   TO->AddId(({"hacha","hacha de guerra","dolores"}));
   return 1;
  }
  case 4: {
   TO->SetStandard(WT_MAZA, 5, P_SIZE_SMALL, M_BRONCE);
   TO->SetShort("un martillo de guerra");
   TO->SetLong(
"Es un viejo martillo de guerra. La cabeza ha sido tallada en forma\n"
"de un grotesco rostro.\n");
   TO->AddId(({"martillo","martillo de guerra"}));
   TO->Set(P_GENDER,GENERO_MASCULINO);
   return 1;
  }
  case 5: {
   TO->SetStandard(WT_LANZA, 5, P_SIZE_SMALL, M_HIERRO);
   TO->SetShort("un fauchard");
   TO->SetLong(
"Una larga lanza de un solo filo con una púa en la parte trasera.\n");
   TO->AddId(({"fauchard","lanza"}));
   TO->Set(P_GENDER,GENERO_MASCULINO);
   return 1;
  }
  case 6: {
   TO->SetStandard(WT_HACHA, 6, P_SIZE_SMALL, M_HIERRO);
   TO->SetShort("un hacha de guerra");
   TO->SetLong("Un hacha con dos hojas, bastante melladas, pero muy afiladas.\n");
   TO->AddId(({"hacha de guerra","hacha"}));
   return 1;
  }
  case 7: {
   TO->SetStandard(WT_ESPADA, 7, P_SIZE_SMALL, M_ACERO);
   TO->SetShort("un flamberge");
   TO->SetLong("Una gran espada de hoja ondulada.\n");
   TO->AddId(({"flamberge","espada"}));
   TO->Set(P_GENDER,GENERO_MASCULINO);
   return 1;
  }
  case 8: {
   TO->SetStandard(WT_LANZA, 6, P_SIZE_SMALL, M_HIERRO);
   TO->SetShort("un enorme arpón");
   TO->SetLong("Un viejo arpón bastante afilado, no obstante.\n");
   TO->AddId(({"arpón","mazo","arpon"}));
   TO->Set(P_GENDER,GENERO_MASCULINO);
   return 1;
  }
  case 9: {
   TO->SetStandard(WT_ALABARDA, 6, P_SIZE_SMALL, M_ACERO);
   TO->SetShort("una oxidada alabarda");
   TO->SetLong("Una alabarda con la hoja mellada.\n");
   TO->AddId(({"alabarda","oxidada alabarda"}));
   return 1;
  }
 }
}


create() {
::create();
 crear_objeto();
 AddId(({"arma"}));
 SetNumberHands(2); // todas son a 2 manos
 SetValue(random(5)); // baratillas, pa que no los jugatas no se pasen...
 SetResetQuality(95);
 SetQuality(90+random(5));
}
