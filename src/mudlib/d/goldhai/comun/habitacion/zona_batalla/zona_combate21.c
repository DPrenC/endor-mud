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

 AddExit("sur",BATALLA("zona_combate29"));
 AddExit("este",BATALLA("zona_combate20"));
 AddExit("oeste",BATALLA("zona_combate22"));
 AddExit("sudeste",BATALLA("zona_combate30"));
 AddExit("suroeste",BATALLA("zona_combate28"));

 SetLocate("llanura de Orkath");
}

