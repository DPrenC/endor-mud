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

 AddExit("norte",BATALLA("zona_combate28"));
 AddExit("sur",BATALLA("zona_combate40"));
 AddExit("este",BATALLA("zona_combate34"));
 AddExit("oeste",BATALLA("zona_combate36"));
 AddExit("nordeste",BATALLA("zona_combate29"));
 AddExit("sudeste",BATALLA("zona_combate41"));
 AddExit("noroeste",BATALLA("zona_combate27"));
 AddExit("suroeste",BATALLA("zona_combate39"));

 AddItem("/guilds/conjuradores/pergamino/pergamino_esfera",REFRESH_REMOVE,1);

 SetLocate("llanura de Orkath");
}

