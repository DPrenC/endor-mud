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
El bosque norte y el río no te permiten mucho más que continuar hacia el\n\
Este y el Oeste por este camino.\n");

#include INC"d_rio_crowy.inc"

 AddExit("oeste",BNORTE("alrededor_crowy3"));
 AddExit("este",BNORTE("alrededor_crowy5"));

 SetLocate("bosque del norte de Goldhai");
}
