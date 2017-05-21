#include "./path.h"

inherit SHOP;

create() {
   ::create();

   SetIntShort("una tienda");
   SetIntLong(
"Varias armaduras decoran las paredes de esta tienda. A pesar de que los "
"enanos son grandes guerreros, no todo el equipo de esta tienda te servira "
"para las grandes campanyas con las que siempre has sonyado.\n");

    AddArticle(PROT("cota"),REFRESH_REMOVE,5);
    AddArticle(PROT("cotaman"),REFRESH_REMOVE,2);
    AddArticle(PROT("yelmo"),REFRESH_REMOVE,6);
    AddArticle(PROT("botas"),REFRESH_REMOVE,8);
   AddArticle(PROT("escudo"),REFRESH_REMOVE,6);
  AddArticle(PROT("escudoxl"),REFRESH_REMOVE,3);
  AddDetail(({"paredes"}),
  "Son de piedra, y entre el variado equipo, puedes ver una armadura de placas.\n");

  AddDetail(({"armaduras","armadura","armadura de placas"}),
  "Del diverso equipo que decora las paredes, es la armadura de placas la que "
  "mas te llama la atencion. Parece desgastada y fuera de venta.\n");
   SetIntBright(80);
   SetIndoors(1);

  AddExit("norte",CIUDAD+"antha11");
  AddExit("sur",CIUDAD+"avcastle11");

  SetLocate("Kha-annu");
}