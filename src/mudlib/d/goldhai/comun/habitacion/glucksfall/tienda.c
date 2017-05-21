#include "path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
inherit SHOP;

create()
{
    ::create();
    SetIntShort("la tienda general");
    SetIntLong("Estás dentro de la tienda general de Glucksfall, un lugar que guarda un claro "
        "contraste entre tanta taberna, armería o herrería. Aquí podrás hallar esos objetos "
        "que precisas en tu vida cotidiana a un precio muy asequible.\n");
    SetIndoors(1);
    SetIntBright(50);
    SetCash(30000);
    SetShopkeeper(PNJ("glucksfall/ronn"));
    SetLastDest("calle7");
    SetNotifyExits(({"este"}));
    AddExit("este","calle7");
    AddDoor("este","la puerta de la calle",
        "Es una gruesa puerta de hierro, como era de esperar en un sitio como éste. Por "
        "supuesto, aquí nadie se fía de nadie.\n",
        ({"puerta","puerta este","puerta de calle","puerta de la calle"}),GENERO_FEMENINO,
        ([P_DOOR_CLOSE_SOUND:SND_SUCESOS("cerrar_metalica"),
        P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
        P_MATERIAL:M_HIERRO,P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT]));
    AddArticle("/obj/torch",REFRESH_REMOVE,5);
    AddArticle("/obj/oil_bottle",REFRESH_REMOVE,3);
    AddArticle("/obj/lighter",REFRESH_REMOVE,2);
    AddArticle(OTRO("pala"),REFRESH_REMOVE,3);
    AddArticle("/obj/sunglasses",REFRESH_REMOVE,([P_VALUE:18]),3);
    AddArticle("/obj/bandage",REFRESH_REMOVE,10);
    AddArticle("/obj/cuerda",REFRESH_REMOVE,3);
    AddArticle("/obj/bcocina",REFRESH_REMOVE,5);
    SetLocate("Glucksfall");
}
