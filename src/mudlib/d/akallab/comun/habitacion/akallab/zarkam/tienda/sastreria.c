/*
DESCRIPCION : sastreria de Maoli
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/tienda/sastreria.c
MODIFICACION: 16-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/
#include "path.h"
#include AK_MACRO
#include <properties.h>
#include <materials.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
#include <wizlevels.h>
inherit SHOP;

create()
{
    ::create();
    SetIntShort("la sastrería de Maoli");
    SetIntLong("Te encuentras en una sastrería. A tu alrededor puedes ver varios percheros y "
        "estanterías con muestras de las distintas prendas de ropa que Maoli, la sastre "
        "propietaria del local, fabrica. Al fondo de esta habitación hay una gran mesa sobre "
        "la que hay varias telas con las que Maoli debe estar trabajando. Bajo la mesa, un "
        "brasero defiende del frío.\n");
    AddDetail(({"estanterias","estanterías"}),"Hay varias estanterías de madera en la "
        "sastrería. Colocadas en ellas puedes ver dobladas algunas prendas de ropa de las "
        "que vende Maoli.\n");
    AddDetail(({"percheros"}),"Algunas de las prendas de ropa que Maoli vende están colgadas "
        "en unos percheros, bien para que no se arruguen, bien porque, como en el caso de las "
        "capas, son demasiado grandes para colocarlas dobladas en las estanterías.\n");
    AddDetail(({"mesa"}),"Al fondo de la habitación hay una gran mesa de madera de roble. Es "
        "en ella donde Maoli trabaja con las telas para hacer la ropa que luego vende.\n");
    AddDetail(({"brasero"}),"Hay un brasero bajo la mesa en la que trabaja Maoli. Las brasas "
        "que contiene dan el calor necesario para calentar el ambiente.\n");
    AddDetail(({"tienda","local","sastreria","sastrería"}),QueryIntLong());
    SetIntNoise((sk_in_shop()?0:"Oyes el fru-fru de la tela con que Maoli trabaja.\n"));
    SetIntSmell("No huele a nada en especial.\n");
    SetLocate("ciudad de Zarkam");
    SetIndoors(1);
    SetIntBright(50);
    CanSell(0);     //El cliente no puede vender a la tienda
    CanAppraise(0); //No se valoran objetos
    CanIdentify(0); //No se identifican objetos
    RemoveDustbin();
    SetShopkeeper(PNJ_Z_CIUDAD("maoli"));
    SetLastDest(Z_CIUDAD("calle_28"));
    SetNotifyExits("oeste");
    AddExit("oeste",Z_CIUDAD("calle_28"));
    AddDoor("oeste","la puerta de la sastrería",
        "Es una gruesa puerta de madera labrada, fuerte y resistente.\n",
        ({"puerta","puerta de sastreria","puerta de sastrería","puerta de la sastreria",
            "puerta de la sastrería"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CLOSE_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CANT_OPEN_MSG:({({"Intentas abrir la puerta, y al no poder, la miras y ves "
                "un cartel:\n'Cerrado toda la noche.'\n","Tratas de abrir la puerta en "
                "la oscuridad, pero no logras encontrar la manija.\n"}),({"@nombre@ trata de "
                "entrar en la sastrería, pero se da cuenta de que cierra durante la noche.\n",
                "Oyes a alguien removerse, jurando en la oscuridad.\n"}),
                "Parece que alguien trata de abrir la puerta.\n"}),
                P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    AddArticle(PROT("camisa"), REFRESH_REMOVE, 3);
    AddArticle(PROT("sombrero"), REFRESH_REMOVE, 1);
    AddArticle(PROT("capa"), REFRESH_REMOVE, 2);
    AddArticle(PROT("pantalon"), REFRESH_REMOVE, 2);
}

init()
{
    ::init();
    if (IS_LEARNER(TP) && TP->QueryInvis()) return;
    SkSay("Hola "+NOMBRE+", bienvenid"+AO+" a mi tienda.\n");
}
