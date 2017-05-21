/*=============================================================*
 |          << GOLDHAI.Bosque Wald [w] Woo@simauria >>         |
 *=============================================================*
 |             Creacion................... 07-02-99            |
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
Caminas por la orilla del río que protege Crowy. En el norte ves a lo lejos\n\
lo que parece ser un pequeño lago, pero tampoco lo sabes con seguridad.\n");

#include INC"d_rio_crowy.inc"

 AddExit("norte",BNORTE("alrededor_crowy15"));
 AddExit("sur",BWALD("alrededor_crowy14"));

 SetLocate("bosque Wald");
}
