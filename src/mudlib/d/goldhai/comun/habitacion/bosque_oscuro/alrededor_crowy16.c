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
Estás andando por un pedregoso camino que han construido alrededor de la\n\
ciudad de Crowy. Desde aquí las murallas parecen mucho más bajas de lo normal\n\
pero el río de protección te impide acercarte mas. Parece ser que no tienes\n\
más opción que continuar por este camino en direccion Norte y Sur.\n");

#include INC"d_rio_crowy.inc"

 AddExit("norte",BOSCURO("alrededor_crowy17"));
 AddExit("sur",BOSCURO("alrededor_crowy15"));

 SetLocate("bosque oscuro de Goldhai");
}
