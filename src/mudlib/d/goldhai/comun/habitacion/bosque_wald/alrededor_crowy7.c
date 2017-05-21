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
El río transcurre a tu lado mientras caminas bordeando la ciudad. No observas\n\
ninguna senda que te permita adentrarte en el bosque, quizás si siguieras el\n\
camino encontrarias alguna forma de conseguirlo.\n");

#include INC"d_rio_crowy.inc"

 AddExit("oeste",BWALD("alrededor_crowy6"));
 AddExit("norte",BWALD("alrededor_crowy8"));

 SetLocate("bosque Wald");
}
