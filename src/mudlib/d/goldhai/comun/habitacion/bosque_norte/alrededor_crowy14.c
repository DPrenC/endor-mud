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
Caminas por una senda que transcurre entre el lago Zinn y el río que bordea\n\
Crowy. En el nordeste puedes ver lo que parece ser un pequeño embarcadero,\n\
aunque no existe posibilidad de ir de forma directa desde aquí así que será\n\
mejor que busques otro camino. Puedes seguir en dirección Oeste y Este.\n");

#include INC"d_rio_crowy.inc"

 AddExit("oeste",BNORTE("alrededor_crowy13"));
 AddExit("este",BNORTE("alrededor_crowy15"));

 SetLocate("bosque del norte de Goldhai");
}
