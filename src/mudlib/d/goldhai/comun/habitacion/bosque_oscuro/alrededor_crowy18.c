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
Desde aquí puedes ver la parte norte de la ciudad a la cual puedes llegar\n\
si continuas por este camino hacia el Norte. Un poco más allá, en el\n\
Noroeste resalta la figura de un enorme faro al cual quizás puedas llegar\n\
si continuas en dirección Oeste adentrandote en el bosque.\n");

#include INC"d_rio_crowy.inc"

 AddDetail(({"faro","luz"}),
"Ves un enorme faro cerca del acantilado.\n");

 AddExit("oeste",BOSCURO("frente_faro2"));
 AddExit("sur",BOSCURO("alrededor_crowy17"));
 AddExit("norte",BNORTE("alrededor_crowy1"));

 SetLocate("bosque oscuro de Goldhai");
}
