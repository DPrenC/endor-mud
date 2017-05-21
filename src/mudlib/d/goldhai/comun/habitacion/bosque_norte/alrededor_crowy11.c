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
Estás rodeado de agua por todos lados. El camino pasa entre el río que\n\
protege Crowy y el lago Zinn en la parte nordeste. Desde luego este es\n\
un mal sitio si tienes fobia al agua.\n");

#include INC"d_rio_crowy.inc"

 AddExit("norte",BNORTE("alrededor_crowy10"));
 AddExit("este",BNORTE("alrededor_crowy12"));

 SetLocate("bosque del norte de Goldhai");
}
