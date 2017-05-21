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
 SetStandard("un oso","oso",4,GENDER_MALE);
 InitChats(3,
   "Worgghhh...\n");
}


