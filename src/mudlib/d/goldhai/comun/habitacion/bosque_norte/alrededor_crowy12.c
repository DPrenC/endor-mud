/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 29-10-98                |
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
Desde aquí se puede ver perfectamente la isla situada en medio del lago\n\
Zinn. Parece un lugar interesante de visitar pero lo que si tienes claro\n\
es que es casi imposible recorrer la distancia a nado, así que tendrás\n\
que buscar otro medio de llegar.\n");

#include INC"d_rio_crowy.inc"

 AddExit("oeste",BNORTE("alrededor_crowy11"));
 AddExit("este",BNORTE("alrededor_crowy13"));

 SetLocate("bosque del norte de Goldhai");
}
