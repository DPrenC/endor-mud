/*
DESCRIPCION : tienda del pueblo de Gaddaro
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/gaddaro/tienda.c
MODIFICACION: 18-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include AK_MACRO
#include <colours.h>
#include <properties.h>
#include <materials.h>
#include <sounds.h>
#include <door.h>
#include <scheduler.h>
#include <wizlevels.h>
inherit SHOP;

create()
{
    ::create();
   SetIntShort("la tienda del pueblo de Gaddaro");
    SetIntLong("Estás en la tienda que hay en el pueblo de Gaddaro. Su propietario es Grumm, "
        "un viejo orco. El local es pequeño pero acogedor, y en sus estanterías podrás "
        "encontrar un poco de todo, ya que Grumm se dedica a comerciar con productos de uso "
        "general.\n");
    AddDetail(({"tienda","local"}),QueryIntLong());
    AddDetail(({"estanterias","productos","estanterías"}),"Las estanterías ocupan gran parte de "
        "las paredes y del interior de la tienda. Están construidas con listones de madera y "
        "en sus lajas puedes observar los más variados productos. Usa "+TC_BOLD+"lista"+
        TC_NORMAL+"para conocer que productos están a la venta.\n");
    SetIntNoise((sk_in_shop()?0:"Oyes a Grumm trajinar con trastos en el almacén de la "
        "tienda.\n"));
    SetIntSmell("Huele a cosas almacenadas durante mucho tiempo.\n");
    SetLocate("pueblo de Gaddaro");
    SetIndoors(1);
    SetIntBright(50);
    CanSell(1);     //El cliente si puede vender a la tienda
    CanAppraise(0); //No se valoran objetos
    CanIdentify(0); //No se identifican objetos
    RemoveDustbin();
    SetShopkeeper(PNJ_GADDARO("grumm"));
    SetLastDest("./calle03");
    SetNotifyExits("sur");
    AddExit("sur",GADDARO("calle03"));
    AddDoor("sur","la puerta de la tienda",
        "Es una gruesa puerta de madera tosca, pero resistente.\n",
        ({"puerta","puerta sur","puerta de tienda","puerta de la tienda"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CLOSE_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CANT_OPEN_MSG:({"Intentas abrir la puerta, y al no poder, la miras y ves un "
                "cartel:\n'Cerrado\nVuelva por la mañana'\n",(:capitalize(TP->QueryName())+
                " trata de entrar en la tienda, pero se da cuenta de que cierra durante la "
                "noche.\n":),"Oyes a alguien intentando abrir una puerta.\n"}),
                P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    AddArticle("/obj/cuerda", REFRESH_REMOVE,1+random(1));
    AddArticle("/obj/candle",REFRESH_REMOVE,d3());
    AddArticle("/obj/torch", REFRESH_REMOVE,5);
    AddArticle("/obj/oil_bottle",REFRESH_REMOVE,4);
    AddArticle("/obj/sunglasses",REFRESH_REMOVE,5);
    AddArticle("/obj/lighter",REFRESH_REMOVE,2);
    AddArticle(OTRO("frasco"), REFRESH_REMOVE,6);
    AddArticle(OTRO("romana"), REFRESH_REMOVE,1);
    AddArticle(OTRO("balanza"), REFRESH_REMOVE,3);
}

init()
{
    ::init();
    if (IS_LEARNER(TP) && TP->QueryInvis()) return;
    SkSay("Hola "+NOMBRE+", bienvenid"+AO+" a mi tienda.\n");
}
