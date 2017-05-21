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

 AddExit("sur",BATALLA("zona_combate27"));
 AddExit("este",BATALLA("zona_combate22"));
 AddExit("oeste",BATALLA("zona_combate24"));
 AddExit("sudeste",BATALLA("zona_combate28"));
 AddExit("suroeste",BATALLA("zona_combate26"));

 SetLocate("llanura de Orkath");
}

