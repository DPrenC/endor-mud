/*=============================================================*
 |          << GOLDHAI.Zona Batalla[w] Woo@simauria >>         |
 *=============================================================*
 |             Creacion................... 27-08-98            |
 |             Ultima Modificacion........ 27-08-98            |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBATALLA;

int beber(string str);

create()
{
 ::create();
 SetIntShort("la llanura de Orkath");

 AddExit("norte",BATALLA("zona_combate"));
 AddExit("sur",BATALLA("zona_combate"));
 AddExit("este",BATALLA("zona_combate"));
 AddExit("oeste",BATALLA("zona_combate"));
 AddExit("nordeste",BATALLA("zona_combate"));
 AddExit("sudeste",BATALLA("zona_combate"));
 AddExit("noroeste",BATALLA("zona_combate"));
 AddExit("suroeste",BATALLA("zona_combate"));

 SetLocate("llanura de Orkath");
}

