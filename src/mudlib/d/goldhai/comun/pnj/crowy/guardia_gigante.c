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
 SetStandard("un guardián gigante","gigante",([GC_LUCHADOR:15+random(5)]),GENERO_MASCULINO);
 SetIds(({"guardián","guardián gigante","guardian","guardian gigante","gigante"}));
 SetShort("un guardián gigante");
 SetLong("\
Los guardianes gigantes son los peores con diferencia. Siempre están deseosos\n\
de entrar en combate, sea con quien sea, por lo que andate con cuidado cuando\n\
pases junto a ellos. Su aspecto es enorme, van vestidos con pieles de animales\n\
que seguramente han matado con sus propias manos y van fuertemente armados.\n");
 SetAlign(-120);
 SetWhimpy(0); // O mata o muere
 SetGoChance(50);

 AddItem("/obj/money",REFRESH_REMOVE,
  (["Money":(["cobre":random(9),"plata":random(7),"oro":random(5)])]));
 AddItem(PROT("coraza_hierro"),REFRESH_REMOVE,SF(wearme));
 AddItem(ARMA("maza_hierro"),REFRESH_REMOVE,SF(wieldme));
  InitChats(2,({"El gigante se rasca la cabeza.\n"}));
  InitAChats(10,({"El gigante grita: ¡¡Lárgate antes de que te aplaste!!\n"}));
}

