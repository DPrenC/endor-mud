/*
DESCRIPCION : humana
FICHERO     : mujer.c
MODIFICACION: 25-06-01 [Tirdos] (basado en mujerkender)
*/
#include "./path.h"
inherit NPC;

int x;
create ()
{
   ::create();
  SetName("una humana");
   SetAds(({"una","la"}));
   SetIds(({"humana"}));

   SetShort("una humana");
   SetLong(
"Ves una bonita muchacha. Es bastante joven, pero quizas su vitalidad\n"
"te enganye. Sus ojos brillan con la curiosidad de una ninya.\n");
   SetRace("humana");
   SetGender (1);
   x=random(20)+2;
   SetLevel(x);
   InitChats(2, ({
"La mujer te mira con curiosidad.\n",
"La muchacha dice: puedo hacer algo por ti?\n",
"La humana tararea una alegre melodia y sonrie.\n"
                 }) );
   InitAChats(10, ({
"la mujer grita presa del panico: AYUDA!! AYUDA!! me atacan!!!",
                 }) );

  SetHands(({ ({"mano derecha", 0,1}), ({"mano izquierda",0,1}) }) );
}
/*-------------------------------------------------------------*/
