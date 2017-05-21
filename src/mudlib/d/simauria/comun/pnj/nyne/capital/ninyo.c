/*
DESCRIPCION : niño humano
FICHERO     : ninyoh.c
MODIFICACION: 11-6-01 [Tirdos] Creacion
--------------------------------------------------------------------------------
*/
#include <moving.h>
#include <combat.h>

inherit NPC;

create ()
{
   ::create();
  SetName("un ninyo humano");
   SetIds(({"ninyo","humano"}));
   SetShort("un ninyo humano");
   SetLong(
"Es un ninyo humano. Parece muy inquieto, y bastante despierto. Te mira con\n"
"mucha curiosidad. Tiene la cara y las manos sucias de jugar con el barro.\n");
   SetRace("humano");
   SetGender (1);
   SetLevel(3);
   SetGoChance(6);
   InitChats(3, ({
     "El ninyo dice: Hola!! ¿Como te llamas?\n",
     "El ninyo dice: Me encanta eso que llevas ahi... me lo das?\n",
     "El ninyo se sienta y se pone a jugar con la tierra...\n",
     "El ninyo comienza a urgarse la nariz.\n",
     "El ninyo rie alegremente\n"
     "El ninyo corretea de un lado a otro.\n",
     "El ninyo te mira y sonrie de oreja a oreja.\n"
                 }) );
   InitAChats(3,({
"El ninyo te mira con una carita de pena y con lagrimas en los ojos.\n",
                 }) );

   SetHands(({ ({"derecha",0,1}), ({"izquierda",0,1})}));
}
