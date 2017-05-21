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

 AddExit("norte",BATALLA("zona_combate39"));
 AddExit("sur",BATALLA("zona_combate8"));
 AddExit("este",BATALLA("zona_combate43"));
 AddExit("oeste",BATALLA("zona_combate45"));
 AddExit("nordeste",BATALLA("zona_combate40"));
 AddExit("sudeste",BATALLA("zona_combate9"));
 AddExit("noroeste",BATALLA("zona_combate38"));
 AddExit("suroeste",BATALLA("zona_combate7"));

 Orkath("medio-elfos");

 SetLocate("llanura de Orkath");
}

