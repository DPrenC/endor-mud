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
Te encuentras en el camino que rodea Crowy. El río que protege la ciudad\n\
no te permite ir al norte al igual que unos arboles hacen lo propio en el\n\
sur. Puedes seguir por la orilla del río en dirección Este y Oeste.\n");

#include INC"d_rio_crowy.inc"

 AddExit("este",BOSCURO("alrededor_crowy1"));
 AddExit("oeste",BOSCURO("alrededor_crowy5"));

 SetLocate("bosque oscuro de Goldhai");
}
