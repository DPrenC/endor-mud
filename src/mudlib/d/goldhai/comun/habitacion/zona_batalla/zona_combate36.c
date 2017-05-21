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

 AddExit("norte",BATALLA("zona_combate27"));
 AddExit("sur",BATALLA("zona_combate39"));
 AddExit("este",BATALLA("zona_combate35"));
 AddExit("oeste",BATALLA("zona_combate37"));
 AddExit("nordeste",BATALLA("zona_combate28"));
 AddExit("sudeste",BATALLA("zona_combate40"));
 AddExit("noroeste",BATALLA("zona_combate26"));
 AddExit("suroeste",BATALLA("zona_combate38"));

 Orkath("elfos-oscuros");

 SetLocate("llanura de Orkath");
}

