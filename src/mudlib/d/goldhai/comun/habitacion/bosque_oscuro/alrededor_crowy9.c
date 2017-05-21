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
Estás en el camino que transcurre entre el río que rodea Crowy y el bosque\n\
oscuro. Puedes proseguir bordeando la ciudad por el Norte y el Este.\n");

#include INC"d_rio_crowy.inc"

 AddExit("norte",BOSCURO("alrededor_crowy10"));
 AddExit("este",BOSCURO("alrededor_crowy8"));

 SetLocate("bosque oscuro de Goldhai");
}
