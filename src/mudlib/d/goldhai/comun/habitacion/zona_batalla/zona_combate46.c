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

 AddExit("norte",BATALLA("zona_combate41"));
 AddExit("sur",BATALLA("zona_combate10"));
 AddExit("este",BATALLA("zona_combate12"));
 AddExit("oeste",BATALLA("zona_combate43"));
 AddExit("nordeste",BATALLA("zona_combate42"));
 AddExit("sudeste",BATALLA("zona_combate11"));
 AddExit("noroeste",BATALLA("zona_combate40"));
 AddExit("suroeste",BATALLA("zona_combate9"));

 Orkath("medio-elfos");

 SetLocate("llanura de Orkath");
}

