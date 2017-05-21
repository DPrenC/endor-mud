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
 SetIntShort("un cruce del camino");
 SetIntLong("\
Te encuentras en un cruce. Al norte puedes ver los muros de la ciudad pero\n\
un r�o te impide ir en esa direcci�n. Un camino transcurre por la orilla del\n\
r�o en direcci�n Este y Oeste. En el Sur hay una peque�a senda que se\n\
introduce dentro del bosque oscuro de Goldhai.\n");

#include INC"d_rio_crowy.inc"

 AddExit("este",BOSCURO("alrededor_crowy5"));
 AddExit("oeste",BOSCURO("alrededor_crowy7"));
 AddExit("sur",BOSCURO("bosque1"));

 SetLocate("bosque oscuro de Goldhai");
}