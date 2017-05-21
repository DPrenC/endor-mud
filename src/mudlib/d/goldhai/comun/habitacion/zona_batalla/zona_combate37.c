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

 AddExit("norte",BATALLA("zona_combate26"));
 AddExit("sur",BATALLA("zona_combate38"));
 AddExit("este",BATALLA("zona_combate36"));
 AddExit("oeste",BATALLA("zona_combate3"));
 AddExit("nordeste",BATALLA("zona_combate27"));
 AddExit("sudeste",BATALLA("zona_combate39"));
 AddExit("noroeste",BATALLA("zona_combate2"));
 AddExit("suroeste",BATALLA("zona_combate4"));

 SetLocate("llanura de Orkath");
}

