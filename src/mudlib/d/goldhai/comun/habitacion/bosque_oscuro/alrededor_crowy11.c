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
El camino transcurre junto a un río que te separa de la ciudad. En el otro\n\
lado un gran bosque te impide ir hacia el oeste. Puedes ir al Norte o al Sur.\n");

#include INC"d_rio_crowy.inc"

 AddExit("norte",BOSCURO("alrededor_crowy12"));
 AddExit("sur",BOSCURO("alrededor_crowy10"));

 SetLocate("bosque oscuro de Goldhai");
}
