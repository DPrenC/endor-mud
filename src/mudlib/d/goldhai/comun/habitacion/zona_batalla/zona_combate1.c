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

 AddExit("norte",BATALLA("zona_combate25"));
 AddExit("sur",BATALLA("zona_combate2"));
 AddExit("este",BATALLA("zona_combate24"));
 AddExit("oeste",BATALLA("borde_rio2"));
 AddExit("sudeste",BATALLA("zona_combate26"));
 AddExit("noroeste",BATALLA("borde_rio3"));
 AddExit("suroeste",BATALLA("borde_rio1"));

 Orkath("elfos-oscuros");

 SetLocate("llanura de Orkath");
}

