/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 01-05-97                |
 |               Ultima Modificacion.. 01-05-97                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GROOM;

create()
{
 ::create();
 SetIntShort("el camino en el parque");
 SetIntLong(
"El parque se extiende desde las últimas casas de la ciudad ciudad hasta los "
"muros que la rodean y se hallan al norte de aquí. Los densos arbustos de "
"esta zona son seguramente refugio de mucho animales.\n");

 AddExit("oeste",CROWY("parque7"));
 AddExit("sur",CROWY("parque2"));

#include "./parque.inc"

}


