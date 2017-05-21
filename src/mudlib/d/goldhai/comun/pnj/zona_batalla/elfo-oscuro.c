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

 SetIds(({"elfo-oscuro","elfo oscuro","elfo"}));

 switch(random(3))
 {
  case 0:
   SetStandard("un guerrero elfo oscuro","elfo-oscuro",([GC_LUCHADOR:10+random(5)]),GENERO_MASCULINO);
   AddId("guerrero elfo oscuro");
   AddId("guerrero elfo");
   AddId("guerrero");
   SetShort("un guerrero elfo oscuro");
   SetLong("\
Ves un elfo oscuro con ansias de lucha. Su piel es de un blanco intenso y\n\
sus ojos oscuros y profundos.\n");
 SetAlign(-15);
 InitChats(3,({
"Un elfo oscuro se rie mientras te mira.\n",
"El elfo oscuro dice: Estoy harto de esperar, necesito sangre.\n",
}));
   break;
  case 1:
   SetStandard("un elfo oscuro","elfo-oscuro",([GC_LUCHADOR:5+random(5)]),GENERO_MASCULINO);
   AddId("elfo oscuro moribundo");
   AddId("moribundo");
   AddId("elfo moribundo");
   SetShort("un elfo oscuro moribundo");
   SetLong("Puedes ver un elfo oscuro lleno de sangre y gimiendo de dolor. Aun así\nsigue en pie preparado para luchar.\n");
   SetHP(QueryMaxHP()/2);
   DropHeart(HEART_HEAL);

   SetAlign(10);
   InitChats(5,({ "Oyes como el elfo oscuro gime de dolor.\n",
   		"Un elfo oscuro grita: Malditos humanos traidores, venid aquí.\n"}));
   break;
  case 2:
   SetStandard("un elfo oscuro","elfo-oscuro",([GC_LUCHADOR:10+random(5)]),GENERO_MASCULINO);
   SetShort("un elfo oscuro");
   SetAlign(0);
   SetLong("Ves un elfo oscuro con ansias de lucha. Su piel es de un blanco intenso y\nsus ojos oscuros y profundos.\n");
   break;
  default:
   SetStandard("un guerrero elfo oscuro","elfo-oscuro",([GC_LUCHADOR:10+random(5)]),GENERO_MASCULINO);
   SetShort("un guerrero elfo oscuro");
   SetAlign(-15);
   SetLong("Ves un elfo oscuro con ansias de lucha. Su piel es de un blanco intenso y\nsus ojos oscuros y profundos.\n");
   InitChats(3,({"Un elfo oscuro se rie mientras te mira.\n",
		"El elfo oscuro dice: Estoy harto de esperar, necesito sangre.\n" }));
  }
}
