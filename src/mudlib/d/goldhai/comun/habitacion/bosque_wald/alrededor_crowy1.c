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
Ves los muros de Crowy al otro lado del río y oyes el bullicio de la gente\n\
al otro lado. En el sur unos enormes arboles te impiden hacer otra cosa que\n\
no sea ir de Este a Oeste por el camino que bordea la ciudad.\n");

#include INC"d_rio_crowy.inc"

 AddExit("oeste",BOSCURO("alrededor_crowy3"));
 AddExit("este",BWALD("alrededor_crowy2"));

 SetLocate("bosque Wald");
}
