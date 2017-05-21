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

 AddExit("norte",BATALLA("zona_combate40"));
 AddExit("sur",BATALLA("zona_combate9"));
 AddExit("este",BATALLA("zona_combate46"));
 AddExit("oeste",BATALLA("zona_combate44"));
 AddExit("nordeste",BATALLA("zona_combate41"));
 AddExit("sudeste",BATALLA("zona_combate10"));
 AddExit("noroeste",BATALLA("zona_combate39"));
 AddExit("suroeste",BATALLA("zona_combate8"));

 Orkath("medio-elfos");

 SetLocate("llanura de Orkath");
}

