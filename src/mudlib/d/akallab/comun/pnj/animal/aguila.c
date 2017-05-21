/*
DESCRIPCION : aguila
FICHERO     : /d/akallab/comun/pnj/aguila.c
MODIFICACION: 02-06-98 [Angor@Simauria] Creacion
              08-10-98 [Angor@Simauria] Varios retoques
*/


#include "path.h"
#include AK_MACRO

inherit NPC;

#include <living.h>
#include <combat.h>
#include <properties.h>

create()
{
  int tipo;
  tipo=random(3);
  ::create();
  SetStandard("aguila","aguila",4+random(4)+tipo*2,GENDER_MALE);
  switch(random(2))
  {
  case 0:
  	{
  	SetShort("un joven aguilucho");
        SetGender(GENDER_MALE);
	SetLong("Es un joven aguilucho con grandes alas enormes y un "
                   "precioso plumaje. Tiene un pico robusto y afilado con el "
                   "que desgarra trozos de carne de sus presas a las que "
                   "atrapa. Por sus movimientos deduces que aun no posee la "
                   "habilidad y fuerza de sus mayores.\n");
        AddId(({"aguilucho"}));
        break;
        }
  case 1:
        {
  	SetShort("un aguila real");
  	SetLong("Se trata de un aguila de coloracion marron oscura, con "
                  "reflejos dorados en la nuca. Suelen habitar en los bosques, "
                  "aunque anidan en zonas rocosas. Su pico es lo "
 		  "suficientemente poderoso como para rasgar la carne de sus "
                  "presas. Posee la precision necesaria para lanzarse en "
                  "picado sobre ti, sacarte los ojos y emprender de nuevo "
                  "el vuelo.\n");
 	break;
	}
  case 2:
  	{
  	SetShort("un aguila imperial");
	SetLong("Es una majestuosa aguila imperial, con unas alas enormes y "
                  "un precioso plumaje. Tiene un pico robusto y afilado con el "
                  "que desgarra trozos de carne de sus presas a las que "
                  "atrapa firmemente con sus poderosas garras.\n");
        break;
        }
  }

  SetNoise("Oyes sus escandalosos chillidos.\n");
  SetWeight(2000);
  AddId(({"aguila"}));

  Set("pnj_zona",1);  //atrapada en su zona de territorio

  SetAggressive(random(2));
  SetGoChance(10);

  SetHands(({({"una garra",0,10}), ({"el pico",0,15})}));

  InitChats(3,({
    "El aguila real se posa ante ti desafiante.\n",
    "El aguila remonta el vuelo con una presa entre sus garras.\n",
    "El aguila vuela majestuosamente con sus grandes alas extendidas.\n",
    "Chiiiiii, chiiiiii!\n",
    "El aguila vuela en circulos observandolo todo desde las alturas.\n",
    "El aguila pasa cerca tuya en vuelo rasante.\n",
    "El aguila te observa desde una rama.\n",
    "El aguila busca algun roedor.\n"  }));

  InitAChats(3,({
    "El aguila pierde algunas plumas en el combate.\n",
    "El aguila se lanza hacia ti.\n",
    "El aguila clava sus ojos en ti.\n"  }));

}









