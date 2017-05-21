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

 AddExit("norte",BATALLA("zona_combate5"));
 AddExit("este",BATALLA("zona_combate7"));
 AddExit("oeste",BATALLA("borde_rio8"));
 AddExit("nordeste",BATALLA("zona_combate45"));
 AddExit("noroeste",BATALLA("borde_rio7"));

 Orkath("medio-elfos");

 SetLocate("llanura de Orkath");
}

