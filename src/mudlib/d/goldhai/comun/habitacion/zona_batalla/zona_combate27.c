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

 AddExit("norte",BATALLA("zona_combate23"));
 AddExit("sur",BATALLA("zona_combate36"));
 AddExit("este",BATALLA("zona_combate28"));
 AddExit("oeste",BATALLA("zona_combate26"));
 AddExit("nordeste",BATALLA("zona_combate22"));
 AddExit("sudeste",BATALLA("zona_combate35"));
 AddExit("noroeste",BATALLA("zona_combate24"));
 AddExit("suroeste",BATALLA("zona_combate37"));

 Orkath("elfos-oscuros");

 SetLocate("llanura de Orkath");
}

