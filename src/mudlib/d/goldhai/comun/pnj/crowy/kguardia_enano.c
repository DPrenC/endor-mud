/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 06-10-98                |
 |               Ultima Modificacion.. 20-04-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <properties.h>

inherit GUARDIAN;

create()
{
  ::create();
 SetStandard("un guardián enano","enano",([GC_LUCHADOR:20]),GENERO_MASCULINO);
 SetIds(({"guardián","guardián enano","guardian","guardian enano","enano"}));
 SetShort("un guardián enano");
 SetLong("\
Fuertes y grandes guerreros, así son los enanos que forman parte de la\n\
guardia que defiende a Crowy de los alborotadores y asesinos. Junto con los\n\
gigantes, los enanos son la raza más común entre los guardianes.\n");
 SetAlign(-20);
 SetWhimpy(0); // O mata o muere
 AddSkill(HAB_ROBAR, 70);

 AddItem(PROT("casco_hierro"),REFRESH_REMOVE,SF(wearme));
 AddItem("/obj/money",REFRESH_REMOVE,
  (["Money":(["cobre":random(9),"plata":random(7),"oro":random(5)])]));

  InitChats(2,({"Un guardián te mira de reojo.\n"}));
}

