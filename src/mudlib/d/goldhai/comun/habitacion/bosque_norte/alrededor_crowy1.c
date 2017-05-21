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
Avanzas por un pequeño camino rodeando la ciudad de Crowy. En el Norte puedes\n\
ver un enorme acantilado que corta subitamente la tierra con el mar. Si ahora\n\
vas hacia el Este o el Sur continuarás la senda de este camino.\n");

#include INC"d_rio_crowy.inc"

 AddExit("norte",ACANTILADO("acantilado_norte1"));
 AddExit("este",BNORTE("alrededor_crowy2"));
 AddExit("sur",BOSCURO("alrededor_crowy18"));

 SetLocate("bosque del norte de Goldhai");
}
