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
Te encuentras en un pequeño cruce del camino. Desde aquí puedes indagar\n\
las interioridades del bosque Wald si vas en dirección Este, o bien seguir\n\
la orilla del río de Crowy de Sur a Norte.\n");

#include INC"d_rio_crowy.inc"

 AddExit("norte",BWALD("alrededor_crowy10"));
 AddExit("sur",BWALD("alrededor_crowy8"));
 AddExit("este",BWALD("bosque10"));

 SetLocate("bosque Wald");
}
