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

 AddExit("norte",BATALLA("zona_combate33"));
 AddExit("sur",BATALLA("zona_combate12"));
 AddExit("este",BATALLA("zona_combate14"));
 AddExit("oeste",BATALLA("zona_combate41"));
 AddExit("nordeste",BATALLA("zona_combate32"));
 AddExit("sudeste",BATALLA("zona_combate13"));
 AddExit("noroeste",BATALLA("zona_combate34"));
 AddExit("suroeste",BATALLA("zona_combate46"));

 Orkath("elfos-oscuros");

 SetLocate("llanura de Orkath");
}

