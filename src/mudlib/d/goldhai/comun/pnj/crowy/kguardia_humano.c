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
 SetStandard("un guardi�n humano","humano",([GC_LUCHADOR:15+random(5)]),GENERO_MASCULINO);
 SetIds(({"guardi�n","guardi�n humano","guardian","guardian humano","humano"}));
 SetShort("un guardi�n humano");
 SetLong("\
Es un humano corpulento y bien equipado cuya misi�n es la de defender a los\n\
habitantes de la ciudad sin importarle el riesgo.\n");
 SetAlign(-40);
 SetWhimpy(0); // O mata o muere
 AddSkill(HAB_ROBAR, 70);

 AddItem(ARMA("espada_larga"),REFRESH_REMOVE,SF(wieldme));
 AddItem(PROT("casco_hierro"),REFRESH_REMOVE,SF(wearme));
 AddItem("/obj/money",REFRESH_REMOVE,
  (["Money":(["cobre":random(9),"plata":random(7),"oro":random(5)])]));

  InitChats(2,({"El guardi�n humano da vueltas alrededor tuyo.\n",
                "Un guardi�n de Crowy te dice: Oye, �no nos hemos visto antes?\n",
               }));
  InitAChats(10,({"El humano grita: ��Huye, si no quieres morir!!\n",
                  "El guardi�n te ataca con todas sus fuerzas.\n",
                }));
}

