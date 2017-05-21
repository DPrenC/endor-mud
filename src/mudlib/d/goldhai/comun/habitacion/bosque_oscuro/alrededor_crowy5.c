/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 06-01-98                |
 |               Ultima Modificacion.. 13-05-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBOSQUE;

create()
{
 ::create();
 SetIntShort("el camino que rodea Crowy");
 SetIntLong("\
Sigues en el camino que rodea Crowy. Puedes ir hacia el Este y el Oeste.\n");

#include INC"d_rio_crowy.inc"

 AddExit("este",BOSCURO("alrededor_crowy4"));
 AddExit("oeste",BOSCURO("alrededor_crowy6"));

 SetLocate("bosque oscuro de Goldhai");
}
