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
"Esta zona del parque est� bastante despejada y s�lo un par de �rboles "
"j�venes rompen el ladera de cesped. El muro que rodea la ciudad se halla "
"al norte de aqu�.\n");

 AddExit("oeste",CROWY("parque5"));
 AddExit("este",CROWY("parque8"));
 AddExit("sur",CROWY("parque1"));

#include "./parque.inc"
}


