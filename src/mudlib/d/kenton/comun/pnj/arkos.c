/*
Fichero: /d/kenton/comun/pnj/arkos.c
descripción: kender artesano en cuero
[K] Korsario@Simauria
Creación: 05/04/98
Ultima modificación [Y] 13/08/2007
*/

#include "path.h"
inherit NPC;

create()
{
    ::create();
    SetName("arkos");
    SetAds(({"el artesano"}));
    SetShort("Arkos, el artesano");
    SetLong(
"Arkos es un humano bastante viejo. No habla demasiado pero parece muy buena "
"persona. Es un artesano de los mejores que podras encontrar.\n");
   SetRace("humano");
   SetGender (1);
   SetLevel(40); // toy hasta los mismo de q se los bajen...
   InitChats(2, ({
// no kiero q se lo bajen facil...
"Arkos te mira de arriba abajo sin mucho interes.\n",
"Arkos dice: Deseas algo en particular?\n" }) );
   InitAChats(8, ({
"Arkos grita: pero que haces??? Pagaras por esto!\n",
"Arkos dice: creo que estas cometiendo un error.\n"}) );
}
