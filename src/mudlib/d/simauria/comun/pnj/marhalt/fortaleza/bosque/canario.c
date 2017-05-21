/*
DESCRIPCION  : un canario
FICHERO      : /d/simauria/comun/pnj/simauria/fortaleza/bosque/canario.c
MODIFICACION : 29-10-98 [Maler]Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <properties.h>

inherit NPC;

create() {
    ::create();
   SetStandard("un canario","pajaro",3,GENDER_MALE);
    SetShort("un canario");
    SetLong("Es un precioso canario amarillo. Va andando y saltando por el suelo "
            "mientras canta alegremente.\n");
    SetNoise("Oyes el maravilloso canto del canario.\n");
    SetWeight(500);
    SetGoChance(25);
    SetStr(3);
    SetDex(5);
    SetCon(2);
    SetInt(1);
    SetHP(QueryMaxHP());
    SetIds(({"canario"}));
    SetAds(({"amarillo","precioso"}));
    SetAC(0);
    SetHands( ({ ({"pico",0,3}) }) );
    InitChats(20,({
      "El canario canta alegremente.\n",
      "El canario se te acerca dando saltitos.\n",
      "El canario picotea algo del suelo.\n",
      "El canario se atusa las plumas con el pico.\n",
      "El canario te mira despreocupadamente.\n",
      "El canario se te queda mirando. Parece interesado.\n"
    }));
    AddWalkZones(ROOMFB(""));
}
