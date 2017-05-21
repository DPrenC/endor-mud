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
 SetStandard("un guardi�n enano","enano",([GC_LUCHADOR:20]),GENERO_MASCULINO);
 SetIds(({"guardi�n","guardi�n enano","guardian","guardian enano","enano"}));
 SetShort("un guardi�n enano");
 SetLong("\
Fuertes y grandes guerreros, as� son los enanos que forman parte de la\n\
guardia que defiende a Crowy de los alborotadores y asesinos. Junto con los\n\
gigantes, los enanos son la raza m�s com�n entre los guardianes.\n");
 SetAlign(-20);
 SetWhimpy(0); // O mata o muere
 AddSkill(HAB_ROBAR, 70);

 AddItem(PROT("casco_hierro"),REFRESH_REMOVE,SF(wearme));
 AddItem("/obj/money",REFRESH_REMOVE,
  (["Money":(["cobre":random(9),"plata":random(7),"oro":random(5)])]));

  InitChats(2,({"Un guardi�n te mira de reojo.\n"}));
}

