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

 AddExit("norte",BATALLA("zona_combate34"));
 AddExit("sur",BATALLA("zona_combate46"));
 AddExit("este",BATALLA("zona_combate42"));
 AddExit("oeste",BATALLA("zona_combate40"));
 AddExit("nordeste",BATALLA("zona_combate33"));
 AddExit("sudeste",BATALLA("zona_combate12"));
 AddExit("noroeste",BATALLA("zona_combate35"));
 AddExit("suroeste",BATALLA("zona_combate43"));

 SetLocate("llanura de Orkath");
}

