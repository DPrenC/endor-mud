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
Estás bordeando la ciudad de Crowy pasando entre un pequeño camino que\n\
transcurre entre el río de protección y el bosque. Puedes continuar en\n\
dirección Norte y Sur.\n");

#include INC"d_rio_crowy.inc"

 AddExit("norte",BOSCURO("alrededor_crowy13"));
 AddExit("sur",BOSCURO("alrededor_crowy11"));

 SetLocate("bosque oscuro de Goldhai");
}
