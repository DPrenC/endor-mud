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
Vas recorriendo un camino que transcurre paralelo a un río que te separa de\n\
las muralas de Crowy. Viene un olor muy fuerte proveniente del agua, la cual\n\
parece que lleva ahí estancada muchos años. Puedes seguir al Norte o al Sur.\n");

#include INC"d_rio_crowy.inc"

 AddExit("norte",BOSCURO("alrededor_crowy16"));
 AddExit("sur",BOSCURO("alrededor_crowy14"));

 SetLocate("bosque oscuro de Goldhai");
}
