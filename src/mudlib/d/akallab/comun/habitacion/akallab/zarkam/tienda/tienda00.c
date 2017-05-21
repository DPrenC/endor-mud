/*
DESCRIPCION : tienda de Nentab
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/tienda/tienda00.c
MODIFICACION: 17-07-98 [Angor@Simauria] Creacion
              20-01-00 [Angor@Simauria] Mas articulos a la venta
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
#include <properties.h>
#include <materials.h>
#include <scheduler.h>
#include <door.h>
#include <sounds.h>
#include <moving.h>
#include <wizlevels.h>
inherit SHOP;

create()
{
    ::create();
    SetIntShort("la tienda de Nentab");
    SetIntLong("Estás en la tienda de Nentab. Es un local no muy grande pero acogedor donde "
        "puedes encontrar un poco de todo. Nentab se dedica a comerciar con productos de uso "
        "general y no se ha especializado en un tipo concreto. Observas que la tienda está "
        "llena de estanterías repletas con los más variados productos.\n");
    AddDetail(({"estanterías","estanterias","productos"}),"Las estanterías ocupan gran parte de "
        "las paredes y del interior de la tienda. Están construidas con listones de madera y "
        "en sus lajas puedes observar los más variados productos. Por la capa de polvo que los "
        "cubre, dirías que hay objetos que deben llevar tiempo aquí, mientras que otros "
        "parecen recién colocados. Usa 'lista' para conocer qué productos están a la venta.\n");
    SetIntNoise((sk_in_shop()?0:"Oyes a Nentab trajinar con trastos en el almacén de la "
        "tienda.\n"));
    SetIntSmell("Huele a cosas almacenadas durante mucho tiempo.\n");
    SetLocate("ciudad de Zarkam");
    SetIndoors(1);
    SetIntBright(50);
    CanSell(1);     //El cliente si puede vender a la tienda
    CanAppraise(0); //No se valoran objetos
    CanIdentify(0); //No se identifican objetos
    RemoveDustbin();
    SetShopkeeper(PNJ_Z_CIUDAD("nentab"));
    SetLastDest(Z_CIUDAD("calle_04"));
    SetNotifyExits("este");
    AddExit("este",Z_CIUDAD("calle_04"));
    AddDoor("este","la puerta de la tienda",
        "Es una gruesa puerta de madera labrada, fuerte y resistente.\n",
        ({"puerta","puerta este","puerta de tienda","puerta de la tienda"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CLOSE_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CANT_OPEN_MSG:({({"Intentas abrir la puerta, y al no poder, la miras y ves "
                "un cartel:\n'Cerrado toda la noche.'\n","Tratas de abrir la puerta en "
                "la oscuridad, pero no logras encontrar la manija.\n"}),({"@nombre@ trata de "
                "entrar en la tienda, pero se da cuenta de que cierra durante la noche.\n",
                "Oyes a alguien removerse, jurando en la oscuridad.\n"}),
                "Parece que alguien trata de abrir la puerta"}),
                P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    AddArticle("/obj/cuerda", REFRESH_REMOVE,3);
    AddArticle("/obj/candle",REFRESH_REMOVE,d3());
    AddArticle("/obj/torch", REFRESH_REMOVE,5);
    AddArticle("/obj/oil_bottle",REFRESH_REMOVE,4);
    AddArticle("/obj/lighter",REFRESH_REMOVE,2);
    AddArticle("/obj/sunglasses",REFRESH_REMOVE,5);
    AddArticle(OTRO("romana"), REFRESH_REMOVE,1);
    AddArticle(OTRO("balanza"), REFRESH_REMOVE,3);
}

init()
{
    ::init();
    if (IS_LEARNER(TP) && TP->QueryInvis()) return;
    SkSay("Hola "+NOMBRE+", bienvenid"+AO+" a mi tienda.\n");
}
