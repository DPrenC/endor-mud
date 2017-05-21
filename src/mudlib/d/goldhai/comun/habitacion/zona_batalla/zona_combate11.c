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

 AddExit("norte",BATALLA("zona_combate12"));
 AddExit("oeste",BATALLA("zona_combate10"));
 AddExit("noroeste",BATALLA("zona_combate46"));

 Orkath("medio-elfos");

 SetLocate("llanura de Orkath");
}

