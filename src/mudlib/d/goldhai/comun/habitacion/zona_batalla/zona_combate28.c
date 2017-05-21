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

 AddExit("norte",BATALLA("zona_combate22"));
 AddExit("sur",BATALLA("zona_combate35"));
 AddExit("este",BATALLA("zona_combate29"));
 AddExit("oeste",BATALLA("zona_combate27"));
 AddExit("nordeste",BATALLA("zona_combate21"));
 AddExit("sudeste",BATALLA("zona_combate34"));
 AddExit("noroeste",BATALLA("zona_combate23"));
 AddExit("suroeste",BATALLA("zona_combate36"));

 Orkath("medio-elfos");

 SetLocate("llanura de Orkath");
}

