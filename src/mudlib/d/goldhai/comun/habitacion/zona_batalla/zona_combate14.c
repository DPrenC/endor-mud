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

 AddExit("norte",BATALLA("zona_combate32"));
 AddExit("sur",BATALLA("zona_combate13"));
 AddExit("este",BATALLA("zona_combate15"));
 AddExit("oeste",BATALLA("zona_combate42"));
 AddExit("nordeste",BATALLA("zona_combate16"));
 AddExit("noroeste",BATALLA("zona_combate33"));
 AddExit("suroeste",BATALLA("zona_combate12"));

 SetLocate("llanura de Orkath");
}

