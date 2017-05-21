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

 AddExit("norte",BATALLA("zona_combate20"));
 AddExit("sur",BATALLA("zona_combate33"));
 AddExit("este",BATALLA("zona_combate31"));
 AddExit("oeste",BATALLA("zona_combate29"));
 AddExit("nordeste",BATALLA("zona_combate19"));
 AddExit("sudeste",BATALLA("zona_combate32"));
 AddExit("noroeste",BATALLA("zona_combate21"));
 AddExit("suroeste",BATALLA("zona_combate34"));

 Orkath("elfos-oscuros");

 SetLocate("llanura de Orkath");
}

