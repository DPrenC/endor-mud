/*=============================================================*
 |          << GOLDHAI.Zona Batalla[w] Woo@simauria >>         |
 *=============================================================*
 |             Creacion................... 27-08-98            |
 |             Ultima Modificacion........ 27-08-98            |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBATALLA;

create()
{
 ::create();
 SetIntShort("la llanura de Orkath");

 AddExit("norte",BATALLA("borde_rio13"));
 AddExit("sur",BATALLA("zona_combate1"));
 AddExit("oeste",BATALLA("borde_rio3"));
 AddExit("noroeste",BATALLA("borde_rio4"));
 AddExit("suroeste",BATALLA("borde_rio2"));

 SetLocate("llanura de Orkath");
}

