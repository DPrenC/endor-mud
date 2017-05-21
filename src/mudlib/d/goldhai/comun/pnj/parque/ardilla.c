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
 SetStandard("una ardilla","ardilla",1,GENDER_FEMALE);
 InitChats(10,
   "Una ardilla coge un fruto del arbol y empieza a roerlo.\n");
}


