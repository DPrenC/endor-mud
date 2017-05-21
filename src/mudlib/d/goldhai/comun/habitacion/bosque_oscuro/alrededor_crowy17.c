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
Estás bordeando la ciudad por un estrecho camino de piedras que te permite\n\
avanzar rápidamente. En la parte oeste el bosque te impide proseguir en esa\n\
dirección entonces solo puedes ir al Norte o al Sur ya que el río de la\n\
ciudad te imposibilita el ir al este.\n");

#include INC"d_rio_crowy.inc"

 AddExit("norte",BOSCURO("alrededor_crowy18"));
 AddExit("sur",BOSCURO("alrededor_crowy16"));

 SetLocate("bosque oscuro de Goldhai");
}
