/*
DESCRIPCION : humana
FICHERO     : mjc.c
MODIFICACION: 8-08-01 [Tirdos] (basado en mujerkender)
*/

inherit NPC;
#include <properties.h>
#include <combat.h>
#include <rooms.h>
#include "./path.h"

int x;
create ()
{
   ::create();
  SetName("una humana");
   SetAds(({"una","la"}));
   SetIds(({"humana"}));

   SetShort("una humana");
   SetLong(W(
"Ves una hermosa mujer, de largos y hermosos cabellos negros. Al mirar sus ojos no puedes "
"sino darte cuenta que es una buena luchadora y no teme enfrentarse a ningún adversario.\n"));
   SetRace("humana");
   SetGender (1);
   SetAggressive(1);
   x=random(23)+10;
   SetLevel(x);
   InitChats(2, ({
"La mujer te mira con temor.\n",
"La muchacha grita: Fuera de mi casa!!!\n",}) );
   InitAChats(10, ({
"la mujer grita presa del panico: AYUDA!! AYUDA!! me atacan!!!",}) );

  SetHands(({ ({"mano derecha", 0,3}), ({"mano izquierda",0,3}) }) );
}
/*-------------------------------------------------------------*/
