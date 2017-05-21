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
Est�s en un peque�o recodo del camina que rodea la ciudad. El bosque te\n\
impide ir en direcci�n sudeste as� que no tienes m�s alternativas que\n\
continuar por este camino hacia el Este o el Sur.\n");

#include INC"d_rio_crowy.inc"

 AddExit("sur",BWALD("alrededor_crowy5"));
 AddExit("este",BWALD("alrededor_crowy7"));

 SetLocate("bosque Wald");
}
