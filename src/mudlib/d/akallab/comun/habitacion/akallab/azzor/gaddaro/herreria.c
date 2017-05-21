/*
DESCRIPCION  : Herreria de Gaddaro
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/gaddaro/herreria.c
BASADO       : herreria de Nandor
MODIFICACION :
18-02-99 [Angor] Creacion
16-09-07 [Angor] Typos corregidos
*/

#include "path.h"
#include AK_MACRO
#include <properties.h>
#include <combat.h>
#include <door.h>
#include <scheduler.h>
#include <sounds.h>
inherit "room/herreria";

create()
{
  ::create();
  SetIntShort("la herrería del pueblo de Gaddaro");
  SetIntLong(
  "Te encuentras en la herreria del pueblo. Es un cobertizo de mediano "
  "tamaño y techo de caña en el que hace un calor sofocante debido a la "
  "fragua donde arde un poderoso fuego para así poder templar el metal. "
  "Junto a la fragua, un gran fuelle permite avivar su fuego. Frente a ti "
  "observas el gran yunque en el que trabaja el herrero.\n");

  AddDetail("yunque",
  "Es un inmenso bloque de metal sobre el que trabaja el herrero "
  "las piezas que forja. Parece bastante pesado.\n");

  AddDetail("fuelle",
  "El fuelle es un aparato formado por una especie de bolsa de cuero "
  "que se pliega como un acordeon. Empuja aire al interior de la forja "
  "para así avivar el fuego que alli arde.\n");
    SetIntNoise("¡El estruendo del yunque te destroza los oídos!\n");
    SetIntSmell("Huele a humo.\n");
    SetIntBright(50);
    SetIndoors(1);
    CanIdentify(0); //No se identifican objetos
    CanAppraise(0); //No se valoran objetos
    CanSell(0,"No compro nada"); //El cliente no puede vender a la tienda
    RemoveDustbin(1);
    SetLocate("pueblo de Gaddaro");
    SetLastDest(GADDARO("calle01"));
    SetNotifyExits("oeste");
    AddExit("oeste",GADDARO("calle01"));
    //SetShopkeeper(PNJ("narad/herrero"));
    AddDoor("oeste","la puerta de la calle",
        "Es una puerta de hierro. No es que nadie vaya a intentar robar aquí, pero "
            "probablemente el herrero se ha hecho él mismo la puerta, y él mismo la repare, "
            "cuestión de economía...\n",
        ({"puerta","puerta oeste","puerta de calle","puerta de la calle"}),GENDER_FEMALE,
        ([P_MATERIAL:M_HIERRO,P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT,
            P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
            P_DOOR_CLOSE_SOUND:SND_SUCESOS("cerrar_metalica"),
            P_DOOR_CANT_OPEN_MSG:({({"Cuando ves que la puerta no se abre, recuerdas que el "
                "herrero también necesita descansar...\n","Buscas una puerta que abrir, pero "
                "en la oscuridad te va a resultar imposible...\n"}),({"@nombre@ trata de "
                "entrar en la herrería, seguramente piensa que los herreros no duermen...\n",
                "Oyes que alguien se remueve furioso en las sombras...\n"}),"Parece que "
                "alguien trata de abrir la puerta...\n"})]));

/* Articulos a la venta */

AddArticle("/std/weapon",REFRESH_REMOVE,1,
([P_SHORT: "espada",
P_LONG:  "espada corta de acero\n",
P_IDS: ({"espada corta","espada"}),
P_WC:8 ,
P_WEIGHT:3500 ,
P_NUMBER_HANDS:1,
P_VALUE:1800,
P_SIZE:P_SIZE_GENERIC,
P_RESET_QUALITY: 100,
P_WEAPON_TYPE:WT_ESPADA,
P_DAM_TYPE:DT_SLASH]));

AddArticle("/std/weapon",REFRESH_REMOVE,2,
([P_SHORT: "guadaña",
P_LONG:  "guadaña de metal\n",
P_IDS: ({"guadaña","guadanya","guadaña de metal"}),
P_WC:4 ,
P_WEIGHT:6000 ,
P_NUMBER_HANDS:2,
P_SIZE:P_SIZE_GENERIC,
P_VALUE:200,
P_RESET_QUALITY: 100,
P_WEAPON_TYPE:WT_ESPADA,
P_DAM_TYPE:DT_SLASH]));

AddArticle("/std/thing",REFRESH_REMOVE,8,
([P_SHORT: "herradura",
P_LONG:  "herradura de caballo\n",
P_IDS: ({"herradura de caballo","herradura"}),
P_WEIGHT:1000 ,
P_VALUE:75,
]));

AddArticle("/std/thing",REFRESH_REMOVE,2,
([P_SHORT: "cubo",
P_LONG:  "cubo de metal\n",
P_IDS: ({"cubo","cubo de metal"}),
P_WEIGHT:1000 ,
P_VALUE:100,
]));

//AddArticle("/d/simauria/comun/objeto/arma/claymore"), REFRESH_REMOVE,1);
//AddArticle("/d/simauria/comun/objeto/arma/daga"), REFRESH_REMOVE,1);

}