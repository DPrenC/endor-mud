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
"Esta zona del parque está bastante despejada y sólo un par de árboles "
"jóvenes rompen el ladera de cesped. El muro que rodea la ciudad se halla "
"al norte de aquí.\n");

 AddExit("oeste",CROWY("parque5"));
 AddExit("este",CROWY("parque8"));
 AddExit("sur",CROWY("parque1"));

#include "./parque.inc"
}


