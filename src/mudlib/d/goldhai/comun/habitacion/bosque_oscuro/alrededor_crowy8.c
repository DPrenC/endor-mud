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
Te encuentras en un camino que bordea la ciudad. El río que la protege te\n\
impide ir al este y al norte. En el otro lado el bosque oscuro te da un\n\
poco de respeto. Puedes ir hacia el Oeste y el Sur.\n");

#include INC"d_rio_crowy.inc"

 AddExit("oeste",BOSCURO("alrededor_crowy9"));
 AddExit("sur",BOSCURO("alrededor_crowy7"));

 SetLocate("bosque oscuro de Goldhai");
}
