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
Pasas por un camino que transcurre entre el río que protege la ciudad y los\n\
campos de trigo situados al norte de ésta. Al norte, en la lejania puedes\n\
ver los arboles que forman el bosque norte de Goldhai.\n");

#include INC"d_rio_crowy.inc"

 AddExit("oeste",BNORTE("alrededor_crowy6"));
 AddExit("este",BNORTE("alrededor_crowy8"));

 SetLocate("bosque del norte de Goldhai");
}
