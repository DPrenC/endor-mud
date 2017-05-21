/*=============================================================*
 |            << GOLDHAI.batalla [w] Woo@simauria >>           |
 *=============================================================*
 |               Creacion............... 05-10-98              |
 |               Ultima Modificacion.... 06-09-99              |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <properties.h>
#include <living.h>


inherit NPC;

create()
{
 ::create();

 SetIds(({"medio-elfo","medio elfo","elfo"}));

 switch(random(3))
 {
  case 0:
   SetStandard("un guerrero medio elfo","medio-elfo",([GC_LUCHADOR:10+random(5)]),GENERO_MASCULINO);
   AddId("guerrero medio elfo");
   AddId("guerrero elfo");
   AddId("guerrero");
   SetShort("un guerrero medio elfo");
   SetLong("Miras al medio elfo, fuerte y alto.\n");
   SetAlign(-5);
   InitChats(3,({ "Un guerrero medio elfo dice: Tengo ganas de pillar un par de elfos oscuros\npara retorcerles el gaznate\n",
		"Un medio elfo mira atento a todos lados en busca del enemigo.\n"}));
   break;
  case 1:
   SetStandard("un medio elfo","medio-elfo",([GC_LUCHADOR:5+random(5)]),GENERO_MASCULINO);
   AddId("medio elfo moribundo");
   AddId("elfo moribundo");
   AddId("moribundo");
   SetShort("un medio elfo moribundo");
   SetLong("Es un medio elfo que yace en tierra sin apenas poder moverse y con abundantes\nheridas que le impiden poder luchar.\n");
   SetHP(QueryMaxHP()/2);
   DropHeart(HEART_HEAL);
   SetAlign(10);
   InitChats(5,({ "Oyes como alguien susurra de forma agónica que le ayudes.\n",
   		"Un medio elfo grita de dolor mientras se retuerce.\n"}));
   break;
  case 2:
   SetStandard("un medio elfo","medio-elfo",([GC_LUCHADOR:10+random(5)]),GENERO_MASCULINO);
   SetShort("un medio elfo");
   SetLong("Miras al medio elfo, fuerte y alto.\n");
   SetAlign(0);
  break;
  default:
   SetStandard("un guerrero medio elfo","medio-elfo",([GC_LUCHADOR:10+random(5)]),GENERO_MASCULINO);
   SetShort("un guerrero medio elfo");
   SetLong("Miras al medio elfo, fuerte y alto.\n");
   SetAlign(-5);
 }
}


