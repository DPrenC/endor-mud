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

 AddExit("norte",BATALLA("zona_combate3"));
 AddExit("sur",BATALLA("zona_combate5"));
 AddExit("este",BATALLA("zona_combate38"));
 AddExit("oeste",BATALLA("borde_rio6"));
 AddExit("nordeste",BATALLA("zona_combate37"));
 AddExit("sudeste",BATALLA("zona_combate45"));
 AddExit("noroeste",BATALLA("borde_rio5"));
 AddExit("suroeste",BATALLA("borde_rio7"));

 SetLocate("llanura de Orkath");
}

