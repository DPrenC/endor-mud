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
 SetStandard("un conejo","conejo",2,GENDER_MALE);
 InitChats(4,({
   "Un conejo come hierba y no te presta atencion.\n",
   "Un conejo corretea delante de tus pies.\n"}));
}


