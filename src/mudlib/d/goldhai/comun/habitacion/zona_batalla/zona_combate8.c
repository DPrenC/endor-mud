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

 AddExit("norte",BATALLA("zona_combate44"));
 AddExit("este",BATALLA("zona_combate9"));
 AddExit("oeste",BATALLA("zona_combate7"));
 AddExit("nordeste",BATALLA("zona_combate43"));
 AddExit("noroeste",BATALLA("zona_combate45"));

 SetLocate("llanura de Orkath");
}

