/*=============================================================*
 |            << GOLDHAI.batalla [w] Woo@simauria >>           |
 *=============================================================*
 |               Creacion............... 06-09-99              |
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

 SetIds(({"humano"}));

 switch(random(3))
 {
  case 0:
   SetStandard("un guerrero humano","humano",([GC_LUCHADOR:10+random(5)]),GENERO_MASCULINO);
   AddId("guerrero humano");
   AddId("guerrero");
   SetShort("un guerrero humano");
   SetLong("Es un humano muy corpulento y lleno de sangre.\n");
   SetAlign(-5);
   InitChats(3,({"El humano te mira de reojo.\n"}));
   break;
  case 1:
   SetStandard("un humano","humano",([GC_LUCHADOR:5+random(5)]),GENERO_MASCULINO);
   AddId("humano moribundo");
   AddId("moribundo");
   SetShort("un humano moribundo");
   SetLong("Es un humano fuerte y grande pero que está repleto de heridas que sangran\nen abundancia.\n");
   SetHP(QueryMaxHP()/2);
   DropHeart(HEART_HEAL);

   SetAlign(10);
   InitChats(5,({ "El humano moribundo te dice: Mata algunos elfos oscuros por mi.\n",
   		"Un humano intenta levantarse pero le es imposible.\n"}));
  break;
  case 2:
   SetStandard("un humano","humano",([GC_LUCHADOR:10+random(5)]),GENERO_MASCULINO);
   SetShort("un humano");
   SetLong("Miras a un humano de pelo castaño y fuerte musculatura.\n");
   SetAlign(0);
  break;
  default:
   SetStandard("un guerrero humano","humano",([GC_LUCHADOR:10+random(5)]),GENERO_MASCULINO);
   AddId("guerrero humano");
   AddId("guerrero");
   SetShort("un guerrero humano");
   SetLong("Es un humano muy corpulento y lleno de sangre.\n");
   SetAlign(-5);
   InitChats(3,({"El humano te mira de reojo.\n"}));
  }
}


