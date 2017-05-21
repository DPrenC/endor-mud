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
El camino sobre el que te encuentras bordea toda la ciudad de Crowy. El río\n\
de protección de la ciudad y el bosque solo te dejan proseguir en dirección\n\
Este y Norte.\n");

#include INC"d_rio_crowy.inc"

 AddExit("norte",BOSCURO("alrededor_crowy8"));
 AddExit("este",BOSCURO("alrededor_crowy6"));

 SetLocate("bosque oscuro de Goldhai");
}
