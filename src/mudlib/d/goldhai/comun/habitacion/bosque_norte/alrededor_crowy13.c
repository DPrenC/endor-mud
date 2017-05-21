/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 29-10-98                |
 |               Ultima Modificacion.. 07-02-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBOSQUE;

create()
{
 ::create();
 SetIntShort("el camino que rodea Crowy");
 SetIntLong("\
La orilla del lago Zinn y del río que bordea Crowy están cerca de tus pies\n\
así que será mejor que no te despistes si no quieres acabar remojado.\n");

#include INC"d_rio_crowy.inc"

 AddExit("oeste",BNORTE("alrededor_crowy12"));
 AddExit("este",BNORTE("alrededor_crowy14"));

 SetLocate("bosque del norte de Goldhai");
}
