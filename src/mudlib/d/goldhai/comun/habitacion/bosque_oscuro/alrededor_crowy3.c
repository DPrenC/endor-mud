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
Estás en el camino que rodea Crowy. Puedes ver los muros de la ciudad en el\n\
norte pero un río te impide llegar. Puedes seguir hacia el Este y el Oeste\n\
ya que unos arboles te impiden ir hacia el sur.\n");

#include INC"d_rio_crowy.inc"

 AddExit("oeste",BOSCURO("alrededor_crowy2"));
 AddExit("este",BWALD("alrededor_crowy1"));

 SetLocate("bosque oscuro de Goldhai");
}
