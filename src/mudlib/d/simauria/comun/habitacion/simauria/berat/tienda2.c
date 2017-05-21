//[Maler]
#include "./path.h"
#include <sounds.h>
#include <door.h>
#include <scheduler.h>

inherit SHOP;

#define NOMBRE          (TP->QueryName())
#define NOMBRE_M        (capitalize NOMBRE)
#define SUF             (TP->QueryGenderEndString())

create(){
    ::create();
    SetIntShort("la armería de Malmabeth");
    SetIntLong("Te encuentras en la armería de Berat, la tienda parece "
    "bastante descuidada, pero ofrece unos objetos muy interesantes. "
     "Las paredes están recubiertas de todo tipo de armaduras y "
     "protecciones. Sobre la mesa puedes ver trozos de cuero y "
     "acero procedentes de alguna armadura.\n");

    AddDetail(({"tienda","local"}),QueryIntLong());
    AddDetail(({"objetos","armaduras","protecciones","armadura"}),
    "Son unas armaduras pesadas y diversas capas, escudos y rodelas. "
    "No parecen estar en venta.\n");
    SetIntSmell("Huele a cuero curtido.\n");
    SetLocate("berat");
    SetIntBright(30);

    AddExit("este","./cmerc2");
    RemoveExit("almacen");
    SetShopkeeper(QUEST+"cuchillo/malmabet");
    SetNotifyExits("este");
    SetLastDest("./cmerc2");
    SetNotifyCloseMsg("@name@ cierra la armería y se marcha hacia el sur.\n");
    SetNotifyOpenMsg("@name@ llega del sur, abre la puerta de la armería y entra.\n");
    AddDoor("este", "la puerta de la calle",
    "Es la puerta que da a la calle del mercado.\n",
    ({"puerta de la calle", "puerta del este", "puerta de salida", "puerta"}),
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"), P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));

    //articulos a la venta
    AddArticle(PROT("casco"), REFRESH_REMOVE,1);
    AddArticle(PROT("coraza"), REFRESH_REMOVE,d2());
    AddArticle(PROT("escudo_rnd"), REFRESH_REMOVE,d4());
    AddArticle(PROT("pantalon"), REFRESH_REMOVE,d2());
    AddArticle("/obj/vialv", REFRESH_REMOVE, 4);
    AddArticle("/obj/vialm", REFRESH_REMOVE, 4);
    AddArticle("/obj/vial", REFRESH_REMOVE, 2);

}

void init()
{
    ::init();

    if (sk_in_shop())
    {
    write("Malmabeth te saluda al entrar diciendo: 'Hola, bienvenid"+SUF+" a mi armería.\n");
    say(  "Malmabeth saluda a "+NOMBRE_M+" cuando entra en la tienda.\n",TP);
    }
}

