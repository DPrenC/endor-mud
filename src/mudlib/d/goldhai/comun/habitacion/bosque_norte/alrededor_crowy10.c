/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 29-10-98                |
 |               Ultima Modificacion.. 08-02-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBOSQUE;

create()
{
 ::create();
 SetIntShort("el camino que rodea Crowy");
 SetIntLong("\
Llegas a un cruce entre los campos de trigo, el río que protege Crowy, el\n\
bosque norte de Goldhai y un lago. Si vas hacia el Oeste o el Sur continuarás\n\
por esta senda mientras que puedes adentrarte en el bosque bordeando el lago\n\
si vas hacia el Norte.\n");

#include INC"d_rio_crowy.inc"

 AddExit("oeste",BNORTE("alrededor_crowy9"));
 AddExit("sur",BNORTE("alrededor_crowy11"));
 AddExit("norte",BNORTE("bosque14"));

 SetLocate("bosque del norte de Goldhai");
}
