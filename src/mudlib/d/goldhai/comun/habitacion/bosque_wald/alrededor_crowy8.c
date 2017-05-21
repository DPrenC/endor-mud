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
El río de protección de Crowy en tu lado Oeste y el bosque Wald en tu lado\n\
este. No encuentras ninguna otra solución que continuar Norte o Sur por\n\
este camino.\n");

#include INC"d_rio_crowy.inc"

 AddExit("norte",BWALD("alrededor_crowy9"));
 AddExit("sur",BWALD("alrededor_crowy7"));

 SetLocate("bosque Wald");
}
