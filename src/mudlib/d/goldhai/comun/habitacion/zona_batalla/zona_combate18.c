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

 AddExit("sur",BATALLA("zona_combate17"));
 AddExit("oeste",BATALLA("zona_combate19"));
 AddExit("suroeste",BATALLA("zona_combate31"));

 SetLocate("llanura de Orkath");
}

