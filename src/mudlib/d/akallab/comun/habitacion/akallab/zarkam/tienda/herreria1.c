/*
DESCRIPCION  : Herreria de Zarkam
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/tienda/herreria.c
BASADO       : herreria de Nandor
MODIFICACION : 21-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
#include <properties.h>
#include <combat.h>
#include <materials.h>
#include <door.h>
#include <sounds.h>
#include <wizlevels.h>
inherit "room/herreria";

create()
{
    ::create();
    SetIntShort("una herrería de la ciudad de Zarkam");
    SetIntLong("Te encuentras en una herrería. Es un local de mediano tamaño en el que hace un "
        "calor sofocante debido a la fragua, el lugar donde arde un poderoso fuego para así "
        "templar el metal. Junto a la fragua, un gran fuelle aviva el fuego de su interior. "
        "Frente a ti observas el gran yunque en el que trabaja el herrero.\n");
    AddDetail("yunque","Es un inmenso bloque de metal sobre el que trabaja el herrero las "
        "piezas que forja. Piensas que debe pesar por lo menos una tonelada.\n");
    AddDetail("fuelle","El fuelle es un aparato formado por una especie de bolsa de cuero que "
        "se pliega como un acordeón. Empuja aire al interior de la forja para así avivar el "
        "fuego que allí arde.\n");
    SetIntNoise("¡El estruendo del yunque te va a destrozar los oídos!\n");
    SetIntSmell("Hueles a humo.\n");
    SetIntBright(50);
    SetIndoors(1);
    SetLocate("ciudad de Zarkam");
    CanIdentify(0); //No se identifican objetos
    CanAppraise(0); //No se valoran objetos
    CanSell(0,"No compro nada"); //El cliente no puede vender a la tienda
    RemoveDustbin(1);
    SetShopkeeper(PNJ_Z_CIUDAD("nagor"));
    SetLastDest(Z_CIUDAD("calle_26"));
    SetNotifyExits("oeste");
    AddExit("oeste",Z_CIUDAD("calle_26"));
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
([P_SHORT: "guadanya",
P_LONG:  "guadanya de metal\n",
P_IDS: ({"guadanya","guadanya de metal"}),
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
}
