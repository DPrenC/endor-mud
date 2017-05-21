/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 29-10-98                |
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
Los campos de trigo situados al norte te impiden proseguir en esa dirección\n\
con lo que no tienes otra opción que continuar bordeando la ciudad hacia\n\
el Este y el Oeste por la orilla del río.\n");

#include INC"d_rio_crowy.inc"

 AddExit("oeste",BNORTE("alrededor_crowy7"));
 AddExit("este",BNORTE("alrededor_crowy9"));

 SetLocate("bosque del norte de Goldhai");
}
