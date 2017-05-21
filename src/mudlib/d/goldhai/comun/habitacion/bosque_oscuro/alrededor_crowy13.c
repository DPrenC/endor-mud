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
El río de proteccioó de la ciudad te impide ir en dirección norte y este, con\n\
lo cual no tienes más remedio que continuar bordeando Crowy hacia el Sur o el\n\
Oeste por este camino.\n");

#include INC"d_rio_crowy.inc"

 AddExit("oeste",BOSCURO("alrededor_crowy14"));
 AddExit("sur",BOSCURO("alrededor_crowy12"));

 SetLocate("bosque oscuro de Goldhai");
}
