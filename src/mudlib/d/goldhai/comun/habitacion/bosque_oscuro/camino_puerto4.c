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

 AddExit("oeste",PUERTO("muelle6"));
 AddExit("sur",BOSCURO("camino_puerto3"));

 SetLocate("bosque oscuro de Goldhai");
}
