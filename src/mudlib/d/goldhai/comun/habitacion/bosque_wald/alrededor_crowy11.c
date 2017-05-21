/*=============================================================*
 |          << GOLDHAI.Bosque Wald [w] Woo@simauria >>         |
 *=============================================================*
 |             Creacion................... 27-08-98            |
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
Vas caminando por un peque�o camino que separa el bosque Wald de la ciudad\n\
de Crowy. Los muros de la ciudad al otro lado del r�o de protecci�n es lo\n\
�nico que ves de ella. En el Norte ves un peque�o cruce que quiz�s te lleve\n\
a alg�n lugar interesante.\n");

#include INC"d_rio_crowy.inc"

 AddExit("norte",BWALD("alrededor_crowy12"));
 AddExit("sur",BWALD("alrededor_crowy10"));

 SetLocate("bosque Wald");
}
