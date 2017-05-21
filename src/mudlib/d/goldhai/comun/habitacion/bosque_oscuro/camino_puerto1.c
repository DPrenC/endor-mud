/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 06-01-98                |
 |               Ultima Modificacion.. 29-10-98                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBOSQUE;

create()
{
 ::create();
 SetIntShort("el camino del puerto");
 SetIntLong("\
Te encuentras en un camino que transcurre a traves del bosque oscuro y que\n\
une el puerto de Goldhai situado al Oeste con la ciudad de Crowy al Este.\n");

 AddDetail(({"camino","senda"}),
"Es un ancho camino de tierra que discurre a traves del bosque oscuro.\n");
 AddExit("este",BOSCURO("alrededor_crowy14"));
 AddExit("oeste",BOSCURO("camino_puerto2"));

 SetLocate("bosque oscuro de Goldhai");
}
