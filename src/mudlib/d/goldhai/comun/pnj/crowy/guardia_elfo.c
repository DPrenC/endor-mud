/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 06-10-98                |
 |               Ultima Modificacion.. 11-05-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <properties.h>

inherit GUARDIAN;

create()
{
  ::create();
 SetStandard("un guardián elfo","elfo",([GC_LUCHADOR:15+random(5)]),GENERO_MASCULINO);
 SetIds(({"guardián","guardián elfo","guardian","guardian elfo","elfo"}));
 SetShort("un guardián elfo");
 SetLong("\
Elegidos por su habilidad en el manejo de las armas algunos elfos han entrado\n\
a formar parte de la guardia que protege la ciudad de Crowy. Su aspecto y su\n\
forma de vestir entra mucho en contraste con el resto de razas que pertenecen\n\
a la guardia. Son altos, rubios, de ojos azules y bien vestidos, pero no te\n\
dejes engañar, a la hora de luchar son igual de fieros o más.\n");
 SetAlign(-20);
 SetWhimpy(0); // O mata o muere
 SetGoChance(50);

 AddItem(PROT("camisa_cuero"),REFRESH_REMOVE,SF(wearme));
 AddItem(ARMA("espada_corta"),REFRESH_REMOVE,SF(wieldme));
 AddItem("/obj/money",REFRESH_REMOVE,
  (["Money":(["cobre":random(9),"plata":random(7),"oro":random(5)])]));

  InitChats(2,({"Un guardián pisa una cucaracha con su pie.\n"}));
  InitAChats(10,({"El guardián elfo grita: Soy un elfo, no te temo.. ¡¡defiendete!!\n"}));
}

