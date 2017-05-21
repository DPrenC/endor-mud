/*=============================================================*
 |          << GOLDHAI.Bosque Wald [w] Woo@simauria >>         |
 *=============================================================*
 |             Creacion................... 27-08-98            |
 |             Ultima Modificacion........ 11-05-99            |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBOSQUE;

create()
{
 ::create();
 SetIntShort("el camino que rodea Crowy");
 SetIntLong("\
Paseas bordeando la orilla del r�o que protege la ciudad. En el nordeste\n\
hay una granja desde la que oyes el ruido de los animales. Si vas hacia el\n\
Este llegar�s a un camino de piedras que parece llevarte al port�n principal\n\
de la granja. Puedes seguir bordeando la ciudad hacia el Norte y el Sur.\n");

#include INC"d_rio_crowy.inc"

 AddExit("este",BWALD("camino_granja1"));
 AddExit("sur",BWALD("alrededor_crowy11"));
 AddExit("norte",BWALD("alrededor_crowy13"));

 SetLocate("bosque Wald");
}
