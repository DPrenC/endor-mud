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
En este lugar hay una pequeña brecha que te permite adentrarte en el bosque\n\
en dirección Norte dejando atrás la ciudad de Crowy. En el nordeste el trigo\n\
abarca una gran parte de la tierra.\n");

#include INC"d_rio_crowy.inc"

 AddExit("oeste",BNORTE("alrededor_crowy5"));
 AddExit("este",BNORTE("alrededor_crowy7"));
 AddExit("norte",BNORTE("bosque13"));

 SetLocate("bosque del norte de Goldhai");
}
