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

 AddExit("norte",BATALLA("zona_combate4"));
 AddExit("sur",BATALLA("zona_combate6"));
 AddExit("este",BATALLA("zona_combate45"));
 AddExit("oeste",BATALLA("borde_rio7"));
 AddExit("nordeste",BATALLA("zona_combate38"));
 AddExit("sudeste",BATALLA("zona_combate7"));
 AddExit("noroeste",BATALLA("borde_rio6"));
 AddExit("suroeste",BATALLA("borde_rio8"));

 SetLocate("llanura de Orkath");
}

