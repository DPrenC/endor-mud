/*   arma_guardias1.c
     Creado por : Nemesis
     Fecha: 28-Jul-01
	 Descripción: Arma de una mano para los guardias kobold.
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
   TO->SetStandard(WT_ESPADA, 3, P_SIZE_SMALL, M_HIERRO);
   TO->SetShort("un basilard");
   TO->SetLong("Es una vieja espada corta de hoja recta un poco mellada.\n");
   TO->AddId(({"espada","espada corta","basilard"}));
   TO->Set(P_GENDER,GENERO_MASCULINO);
   return 1;
  }
  case 1: {
   TO->SetStandard(WT_ESPADA, 4, P_SIZE_SMALL, M_ACERO);
   TO->SetShort("una espada ancha");
   TO->SetLong("Es una pequeña espada ancha.\n");
   TO->AddId(({"espada","espada ancha"}));
   return 1;
  }
  case 2: {
   TO->SetStandard(WT_MAZA, 5, P_SIZE_SMALL, M_BRONCE);
   TO->SetShort("una maza negra");
   TO->SetLong("Una maza metálica ennegrecida por los años.\n");
   TO->AddId(({"maza","maza negra"}));
   return 1;
  }

  case 3: {
   TO->SetStandard(WT_HACHA, 4, P_SIZE_SMALL, M_HIERRO);
   TO->SetShort("un hacha de mano");
   TO->SetLong("Una vieja hacha de mano.\n");
   TO->AddId(({"hacha","hacha de mano"}));
   return 1;
  }
  case 4: {
   TO->SetStandard(WT_MAZA, 6, P_SIZE_SMALL, M_ACERO);
   TO->SetShort("una maza de pinchos");
   TO->SetLong("Es una maza metálica con puntiagudos pinchos por toda ella.\n");
   TO->AddId(({"maza","maza de pinchos"}));
   TO->SetDamageType(DT_SLASH);
   return 1;
  }
 case 5: {
   TO->SetStandard(WT_MANGUAL, 5, P_SIZE_SMALL, M_HIERRO);
   TO->SetShort("un mangual");
   TO->SetLong("Aunque la cadena esta llena de oxido, las tres colas estan en perfectas condiciones.\n");
   TO->AddId(({"mangual"}));
   return 1;
  }
 case 6: {
   TO->SetStandard(WT_HACHA, 4, P_SIZE_SMALL, M_HIERRO);
   TO->SetShort("un mugriento catri");
   TO->SetLong("Una pequeña hacha con el filo mellado y restos de sangre negruzca.\n");
   TO->AddId(({"catri","hacha","mugriento catri"}));
   TO->Set(P_GENDER,GENERO_MASCULINO);
   return 1;
  }
 case 7: {
   TO->SetStandard(WT_ESGRIMA, 4, P_SIZE_SMALL, M_ACERO);
   TO->SetShort("un sable dentado");
   TO->SetLong("Un sable de larga hoja mellada, más que dentada.\n");
   TO->AddId(({"sable","sable dentado","espada"}));
   TO->SetDamageType(DT_SLASH);
   return 1;
  }
 case 8: {
   TO->SetStandard(WT_MAZA, 6, P_SIZE_SMALL, M_NINGUNO);
   TO->SetShort("un plombee");
   TO->SetLong("Un poderoso mazo lastrado con plomo.\n");
   TO->AddId(({"plombee","mazo"}));
   TO->SetMaterial("plomo");
   TO->Set(P_GENDER,GENERO_MASCULINO);
   return 1;
  }
 case 9: {
   TO->SetStandard(WT_ESPADA, 6, P_SIZE_SMALL, M_ACERO);
   TO->SetShort("un shashqa");
   TO->SetLong("Una espada de hoja ligeramente curvada.\n");
   TO->AddId(({"shashqa","espada"}));
   TO->Set(P_GENDER,GENERO_MASCULINO);
   return 1;
  }
 }
}


create() {
::create();
crear_objeto();
AddId(({"arma"}));
SetValue(random(5));
SetResetQuality(95);
SetQuality(90+random(5));
}
