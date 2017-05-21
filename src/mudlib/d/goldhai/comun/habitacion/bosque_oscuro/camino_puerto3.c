/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 06-01-98                |
 |               Ultima Modificacion.. 06-01-98                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBOSQUE;

create()
{
 ::create();

 AddExit("norte",BOSCURO("camino_puerto4"));
 AddExit("este",BOSCURO("frente_faro1"));

 SetLocate("bosque oscuro de Goldhai");
}
