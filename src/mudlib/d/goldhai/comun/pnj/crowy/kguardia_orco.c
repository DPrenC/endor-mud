/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 06-10-98                |
 |               Ultima Modificacion.. 23-02-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <properties.h>

inherit GUARDIAN;

create()
{
  ::create();
 SetStandard("un guardián orco","orco",([GC_LUCHADOR:20]),GENERO_MASCULINO);
 SetIds(({"guardián","guardián orco","guardian","guardian orco","orco"}));
 SetShort("un guardián orco");
 SetLong("\
Es uno de los guardianes de la ciudad de Crowy, un orco fuerte y robusto cuya\n\
misión es proteger a los habitantes del lugar. Tiene la cara seria y la verdad\n\
es que su aspecto atemoriza bastante así que será mejor que no le provoques.\n");
 SetAlign(-100);
 SetWhimpy(0); // O mata o muere

 AddItem(ARMA("hacha_combate"),REFRESH_REMOVE,SF(wieldme));
 AddItem("/obj/money",REFRESH_REMOVE,
  (["Money":(["cobre":random(9),"plata":random(7),"oro":random(5)])]));
 AddItem(PROT("yelmo_orco"),REFRESH_REMOVE,SF(wearme));
  InitChats(5,({"El guardián orco te mira desconfiadamente.\n",
                "El guardián empieza a juguetear con su hacha.\n",
                "El guardián orco dice: Que día más aburrido.\n"}));
  InitAChats(10,({"El guardián orco grita: ¡¡Vas a morir!!\n",
                  "El guardián orco se defiende como puede.\n"}));
}

