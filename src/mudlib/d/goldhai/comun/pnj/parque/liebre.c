/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 01-05-97                |
 |               Ultima Modificacion.. 01-05-97                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <properties.h>


inherit NPC;

create()
{
 ::create();
 SetStandard("una liebre","liebre",1,GENDER_FEMALE);
 AddId("liebre");
 SetAlign(0);
 SetHands(({
           ({"pata izquierda",0,1}),
           ({"pata derecha",0,1})
         }));
 InitChats(10,
   "Una liebre salta y se aleja de ti.\n");
}


