/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 27-04-97                |
 |               Ultima Modificacion.. 23-02-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <properties.h>
#include <combat.h>

inherit SHOP;

create()
{
  ::create();
 SetIntShort("la armeria de Ernes");
 SetIntLong(
"Estás en la armeria del viejo Ernes. Parece que haya pasado un grupo de mil\n\
mamuts al menos a juzgar por el aspecto sucio y rastrero que tiene. Pero\n\
ves tantas armas y armaduras a tu alrededor que eso es lo que menos te\n\
importa en estos momentos. Si te interesa comprar algo puedes pedir la 'lista'.\n");
 SetIndoors(1); // 1: A cubierto  0: A descubierto
 SetIntBright(40);
 SetIntNoise("No oyes nada especial o que te recuerde algo.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddItem(PNJ("crowy/guardia_orco"),REFRESH_DESTRUCT);
 AddItem(PNJ("crowy/guardia_gigante"),REFRESH_DESTRUCT);

 AddExit("sur",CROWY("calle6"));
 SetLocate("crowy");
 RemoveDustbin();
 SetShopkeeper(PNJ("crowy/ernes"));

 AddArticle("/obj/arco",REFRESH_REMOVE,4);
 AddArticle("/obj/carcaj",REFRESH_REMOVE,6);

 AddArticle("/std/weapon",REFRESH_REMOVE,2,
    ([P_SHORT: "una espada de hojalata",
      P_LONG:  "Es una espada normal de hojalata como las que usan los niños para jugar.\n",
      P_IDS: ({"espada","espada de hojalata"}),
      P_WC: 2,
      P_VALUE: 110,
      P_GENDER: GENERO_FEMENINO,
      P_NUMBER: NUMERO_SINGULAR,
      P_WEIGHT: 1000,
      P_WEAPON_TYPE:WT_ESPADA,
      P_DAM_TYPE:DT_SLASH]));
 AddArticle("/std/weapon",REFRESH_REMOVE,1,
    ([P_SHORT: "una espada larga",
      P_LONG:  "Es una espada larga de acero similar a las de los caballeros.\n",
      P_IDS: ({"espada","espada larga"}),
      P_WC: 5,
      P_WEIGHT: 2600,
      P_VALUE: 440,
      P_GENDER: GENERO_FEMENINO,
      P_NUMBER: NUMERO_SINGULAR,
      P_NUMBER_HANDS:2,
      P_WEAPON_TYPE:WT_ESPADA,
      P_DAM_TYPE:DT_SLASH]));
 AddArticle("/std/weapon",REFRESH_REMOVE,2,
    ([P_SHORT: "un cuchillo orco",
      P_LONG:  "Un cuchillo orco rustico con empuñadura de madera y con la hoja oxidada.\n",
      P_IDS: ({"cuchillo","cuchillo orco"}),
      P_WC: 1,
      P_WEIGHT: 1100,
      P_VALUE: 130,
      P_GENDER: GENERO_MASCULINO,
      P_NUMBER: NUMERO_SINGULAR,
      P_NUMBER_HANDS: 1,
      P_WEAPON_TYPE:WT_CUCHILLO,
      P_DAM_TYPE:DT_PIERCE]));
 AddArticle("/std/weapon",REFRESH_REMOVE,1,
    ([P_SHORT: "un hacha de leñador",
      P_LONG:  "Una simple hacha de leñador, bien afilada con la que ademas de poder\n\cortar a alguien igual puedes cortar un arbol.\n",
      P_IDS: ({"hacha de lenyador","hacha de leñador","hacha"}),
      P_WC: 4,
      P_WEIGHT: 3000,
      P_VALUE: 250,
      P_NUMBER_HANDS: 1,
      P_GENDER: GENERO_FEMENINO,
      P_NUMBER: NUMERO_SINGULAR,
      P_WEAPON_TYPE:WT_HACHA,
      P_DAM_TYPE:DT_SLASH]));
 AddArticle(ARMA("hacha_combate"),REFRESH_REMOVE,1);
 AddArticle(ARMA("maza_madera"),REFRESH_REMOVE,5);
 AddArticle("/std/weapon",REFRESH_REMOVE,3,
    ([P_SHORT: "una lanza de madera",
      P_LONG:  "Una lanza de madera no muy util para el combate cuerpo a cuerpo pero que si\n"+"aprendes a lanzarla te puede servir de gran ayuda.\n",
      P_IDS: ({"lanza de madera","lanza"}),
      P_WC: 2,
      P_WEIGHT: 500,
      P_VALUE: 70,
      P_GENDER: GENERO_FEMENINO,
      P_NUMBER: NUMERO_SINGULAR,
      P_NUMBER_HANDS: 1,
      P_WEAPON_TYPE:WT_LANZA,
      P_DAM_TYPE:DT_PIERCE]));
}