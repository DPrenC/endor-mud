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
 SetStandard("un guardi�n elfo","elfo",([GC_LUCHADOR:15+random(5)]),GENERO_MASCULINO);
 SetIds(({"guardi�n","guardi�n elfo","guardian","guardian elfo","elfo"}));
 SetShort("un guardi�n elfo");
 SetLong("\
Elegidos por su habilidad en el manejo de las armas algunos elfos han entrado\n\
a formar parte de la guardia que protege la ciudad de Crowy. Su aspecto y su\n\
forma de vestir entra mucho en contraste con el resto de razas que pertenecen\n\
a la guardia. Son altos, rubios, de ojos azules y bien vestidos, pero no te\n\
dejes enga�ar, a la hora de luchar son igual de fieros o m�s.\n");
 SetAlign(-20);
 SetWhimpy(0); // O mata o muere
 SetGoChance(50);

 AddItem(PROT("camisa_cuero"),REFRESH_REMOVE,SF(wearme));
 AddItem(ARMA("espada_corta"),REFRESH_REMOVE,SF(wieldme));
 AddItem("/obj/money",REFRESH_REMOVE,
  (["Money":(["cobre":random(9),"plata":random(7),"oro":random(5)])]));

  InitChats(2,({"Un guardi�n pisa una cucaracha con su pie.\n"}));
  InitAChats(10,({"El guardi�n elfo grita: Soy un elfo, no te temo.. ��defiendete!!\n"}));
}

