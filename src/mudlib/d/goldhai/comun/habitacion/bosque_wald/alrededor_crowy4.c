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
Caminas por el camino que rodea la ciudad de Crowy, con el río de protección\n\
al norte y un bosque infranqueable al sur.\n");

#include INC"d_rio_crowy.inc"

 AddExit("oeste",BWALD("alrededor_crowy3"));
 AddExit("este",BWALD("alrededor_crowy5"));

 SetLocate("bosque Wald");
}
