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

 AddExit("norte",BATALLA("zona_combate30"));
 AddExit("sur",BATALLA("zona_combate42"));
 AddExit("este",BATALLA("zona_combate32"));
 AddExit("oeste",BATALLA("zona_combate34"));
 AddExit("nordeste",BATALLA("zona_combate31"));
 AddExit("sudeste",BATALLA("zona_combate14"));
 AddExit("noroeste",BATALLA("zona_combate29"));
 AddExit("suroeste",BATALLA("zona_combate41"));

 SetLocate("llanura de Orkath");
}

