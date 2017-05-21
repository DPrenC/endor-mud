/*=============================================================*
 |          << GOLDHAI.Bosque Wald [w] Woo@simauria >>         |
 *=============================================================*
 |             Creacion................... 07-02-99            |
 |             Ultima Modificacion........ 13-05-99            |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBOSQUE;

create()
{
 ::create();
 SetIntShort("el camino que rodea Crowy");
 SetIntLong("\
Estás en un pequeño recodo del camino que rodea la ciudad. El bosque y el\n\
río solo te permiten que continues por este camino hacia el Norte o hacia\n\
el Este, según desees.\n");

#include INC"d_rio_crowy.inc"

 AddExit("este",BWALD("alrededor_crowy13"));
 AddExit("norte",BWALD("alrededor_crowy15"));

 SetLocate("bosque Wald");
}
