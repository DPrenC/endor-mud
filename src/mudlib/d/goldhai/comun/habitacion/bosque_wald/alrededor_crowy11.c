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
Vas caminando por un pequeño camino que separa el bosque Wald de la ciudad\n\
de Crowy. Los muros de la ciudad al otro lado del río de protección es lo\n\
único que ves de ella. En el Norte ves un pequeño cruce que quizás te lleve\n\
a algún lugar interesante.\n");

#include INC"d_rio_crowy.inc"

 AddExit("norte",BWALD("alrededor_crowy12"));
 AddExit("sur",BWALD("alrededor_crowy10"));

 SetLocate("bosque Wald");
}
