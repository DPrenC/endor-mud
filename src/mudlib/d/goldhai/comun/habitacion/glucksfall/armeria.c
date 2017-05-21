#include "path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
inherit SHOP;

create()
{
    ::create();
    SetIntShort("una armería");
    SetIntLong("Has entrado a la tienda de armas de la ciudad. Nunca jamás habías visto tantas "
        "armas y de tantos tipos distintos, es algo impresionante. Si la lucha no es lo tuyo "
        "puedes salir de este lugar y llegar a la avenida Djorn.\n");
    SetIndoors(1);
    SetIntBright(50);
    SetCash(30000);
    SetIntSmell("No hueles nada especial\n");
    SetIntNoise("No escuchas nada importante\n");
    SetShopkeeper(PNJ("glucksfall/tuliel"));
    SetLastDest("calle5");
    SetNotifyExits(({"este"}));
    AddExit("este","calle5");
    AddDoor("este","la puerta de la calle",
        "Es una gruesa puerta de hierro, como era de esperar en un sitio como éste. Por "
        "supuesto, aquí nadie se fía de nadie.\n",
        ({"puerta","puerta este","puerta de calle","puerta de la calle"}),GENERO_FEMENINO,
        ([P_DOOR_CLOSE_SOUND:SND_SUCESOS("cerrar_metalica"),
        P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
        P_MATERIAL:M_HIERRO,P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT]));
    AddArticle("/obj/arco",REFRESH_REMOVE,3);
    AddArticle("/obj/carcaj",REFRESH_REMOVE,3);
    AddArticle(ARMA("espada_elfica"),REFRESH_REMOVE,2);
    AddArticle(PROT("cota_mallas"),REFRESH_REMOVE,3);
    AddArticle(PROT("escudo_orco"),REFRESH_REMOVE,3);
    AddArticle(PROT("coraza_acero"),REFRESH_REMOVE,3);
    AddArticle(PROT("escudo_acero3"),REFRESH_REMOVE,3);
    AddArticle(PROT("yelmo_orco"),REFRESH_REMOVE,3);
    AddArticle(ARMA("hacha_combate"),REFRESH_REMOVE,4);
    AddArticle(ARMA("abanico"),REFRESH_REMOVE,3);
    AddArticle(ARMA("espada_larga"),REFRESH_REMOVE,3);
    AddArticle(ARMA("espada_negra"),REFRESH_REMOVE,3);
    SetLocate("Glucksfall");
}
