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
 SetStandard("un osezno","oso",3,GENDER_MALE);
 AddId("osezno");
 SetHands(({
           ({"pata izquierda",0,1}),
           ({"pata derecha",0,1})
         }));
 SetAlign(-30);
 InitChats(3,
   "Un osezno levanta las patas delanteras y te intenta atemorizar.\n");
}


