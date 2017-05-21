/*
DESCRIPCION : un cuervo
FICHERO     : /d/akallab/comun/pnj/animal/cuervo.c
MODIFICACION: 27-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

inherit NPC;
#include <living.h>
#include <combat.h>

create() {
  ::create();
 SetName("cuervo");
  SetShort("un cuervo negro");
  SetLong("Es un cuervo negro que no para de graznar.\n");
  SetRace("cuervo");
  SetGender(GENDER_NEUTER);
  SetNoise("Oyes sus escandalosos graznidos.\n");
  SetWeight(2000);
  SetStr(2);
  SetDex(10);
  SetCon(1);
  SetInt(1);
  SetIds(({"cuervo"}));
  AddId("pajaro");
  SetAds(({"negro","escandaloso"}));
  SetLevel(2);
  SetAlign(-100);
  SetAC(1);
  SetHands(({({"una pata",0,10}),
         ({"pico",0,10})}));
  InitChats(20,({
    "GRUAKKKKKK....GRUAKKKKKK.\n",
    "El cuervo se mueve de un lado a otro.\n",
    "El cuevo no para de graznar ruidosamente.\n",
    "El cuervo parece nervioso por tu presencia.\n",
  }));

}
