inherit NPC;
#include <living.h>
#include <combat.h>

create() {
  ::create();
 SetStandard("lobo","lobo",5,GENDER_MALE);
  SetShort("un lobo negro");
  SetLong("Es una gran lobo negro con afilados colmillos. Parece muy agresivo.\n");
  SetNoise("Oyes sus roncos grunyidos.\n");
  SetWeight(20000);
  SetGoChance(25);
  SetStr(8);
  SetDex(8);
  SetCon(4);
  SetInt(1);

  SetIds(({"lobo"}));
  AddId("lobo");

  SetAggressive((random(3)==0?0:1));
  SetAds(({"negro","feroz"}));
  SetAlign(0);
  SetHands(({({"pata delantera derecha",0,10}),
         ({"pata delantera izquierda",0,10}),
         ({"boca",0,10})}));
  InitChats(20,({
    "GRRRRR....GRRRRR.\n",
    "El lobo grunye ferozmente, arquea el lomo y muestra los colmillos.\n",
    "Este animal parece muy peligroso. No te quita el ojo de encima.\n",
    "GRRRRR....GRRRRR.\n",
    "El lobo aulla con fuerza.\n",
    "Parece dispuesto a atarcarte en cualquier momento de descuido.\n"      }));

}
