#include "./path.h"

inherit SHOP;

create() {
   ::create();

   SetIntShort("una tienda");
   SetIntLong(
"La tienda esta bien iluminada. Hay varios objetos en una estanteria y puedes "
"ver la entrada al almacen detras del mostrador, donde se atiende a los "
"clientes. Hay una salida trasera que lleva a la Avenida del Castillo.\n");

  AddDetail(({"objetos","varios objetos"}),
  "Algunas botellas y jarrones. No tienen nada de especial.\n");
  AddDetail(({"algunas botellas","botellas","jarrones"}),
  "Esos objetos estan en la estanteria, fuera de tu alcance.\n");
  AddDetail(({"estanteria"}),
  "Esta en un lateral del mostrador, y hay varios objetos en ella.\n");
  AddDetail(({"mostrador"}),
  "Es de piedra y de una altura media.\n");

  AddArticle(OTRO("mapa"),REFRESH_REMOVE,8);
  AddArticle("/obj/cuerda",REFRESH_REMOVE,5);
  AddArticle("/obj/bag");
  AddArticle("/obj/candle",REFRESH_REMOVE,d4());
  AddArticle("/obj/torch",REFRESH_REMOVE,4);
  AddArticle("/obj/oil_bottle",REFRESH_REMOVE,3);
  AddArticle("/obj/lighter",REFRESH_REMOVE,1);
   AddArticle(PROT("bota_monta"),REFRESH_REMOVE,2);
   SetIntBright(80);
   SetIndoors(1);

  AddExit("norte",CIUDAD+"antha8");
  AddExit("sur",CIUDAD+"avcastle8");

  SetLocate("Kha-annu");
}