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

 AddExit("norte",BATALLA("zona_combate18"));
 AddExit("sur",BATALLA("zona_combate16"));
 AddExit("oeste",BATALLA("zona_combate31"));
 AddExit("noroeste",BATALLA("zona_combate19"));
 AddExit("suroeste",BATALLA("zona_combate32"));

 Orkath("elfos-oscuros");

 SetLocate("llanura de Orkath");
}

