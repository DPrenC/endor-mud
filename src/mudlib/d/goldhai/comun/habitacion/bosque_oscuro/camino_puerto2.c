/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 06-01-98                |
 |               Ultima Modificacion.. 18-11-98                |
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
 AddExit("este",BOSCURO("camino_puerto1"));
 AddExit("oeste",PUERTO("puerto1"));

 AddFlor();
 SetLocate("bosque oscuro de Goldhai");
}
