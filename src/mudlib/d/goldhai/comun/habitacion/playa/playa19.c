/*=============================================================*
 |            << GOLDHAI.Playa [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 29-10-98                |
 |               Ultima Modificacion.. 29-10-98                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GPLAYA;

create()
{
 ::create();

 AddExit("oeste",PLAYA("playa18"));
 AddExit("este",PLAYA("playa20"));

 SetLocate("playa norte de Goldhai");
}
