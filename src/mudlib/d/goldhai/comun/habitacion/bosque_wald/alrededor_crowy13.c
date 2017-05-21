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
Continuas en el camino que rodea la ciudad de Crowy. Tienes el río de la\n\
ciudad en el suroeste y en el este los arboles del bosque te impiden ir\n\
en esa dirección. Las murallas de la ciudad son infranqueables desde aquí.\n");

#include INC"d_rio_crowy.inc"

 AddExit("oeste",BWALD("alrededor_crowy14"));
 AddExit("sur",BWALD("alrededor_crowy12"));

 SetLocate("bosque Wald");
}
