/*
DESCRIPCION : zapateria de Sebte
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/tienda/zapateria.c
MODIFICACION: 23-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
#include <wizlevels.h>
#include AK_MACRO
inherit SHOP;

create()
{
    ::create();
    SetIntShort("la zapatería de Sebte");
    SetIntLong("Te encuentras en la planta baja de la casa de Sebte el zapatero.\nSebte emplea "
        "esta habitación de la casa como lugar de trabajo. Observas una gran chimenea de piedra "
        "en la que arde un agradable fuego. Junto a ella se encuentran un taburete en el que "
        "Sebte suele trabajar y varias cajas con materiales y herramientas.\n");
    AddDetail(({"cajas","materiales","herramientas"}),"Junto al lugar en el que Sebte trabaja, "
        "hay varias cajas de madera. En ellas guarda los materiales y las herramientas que "
        "necesita para fabricar zapatos.\n");
    AddDetail(({"leñero","lenyero"}),"Es una especie de gran cajón que hay junto a la chimenea. "
        "En él se colocan algunos troncos de madera, con los que más tarde se alimentará el "
        "fuego. En las frías noches de invierno se agradece no tener que salir fuera a por "
        "madera...\n");
    AddDetail(({"taburete"}),"Es un bajo taburete de madera que está junto a la chimenea y "
        "sobre el que suele sentarse Sebte para trabajar.\n");
    AddDetail(({"chimenea","fuego"}),"En la habitación hay una gran chimenea de piedra donde "
        "arde un agradable fuego que calienta el ambiente. Adosado a ella hay un gran leñero "
        "del que Sebte coge madera para alimentar el fuego cuando ve que éste decae. Sebte "
        "suele trabajar sentado al calor del fuego en el taburete que hay junto a la chimenea.\n");
    AddDetail(({"tienda","local","zapateria","zapatería"}),QueryIntLong());
    SetIntNoise((sk_in_shop()?0:"Oyes como Sebte trabaja al calor del fuego.\n"));
    SetIntSmell("La madera desprende un agradable olor al quemarse.\n");
    SetLocate("ciudad de Zarkam");
    SetIndoors(1);
    SetIntBright(50);
    CanSell(0);     //El cliente no puede vender a la tienda
    CanAppraise(0); //No se valoran objetos
    CanIdentify(0); //No se identifican objetos
    RemoveDustbin();
    SetShopkeeper(PNJ_Z_CIUDAD("sebte"));
    SetLastDest(Z_CIUDAD("calle_27"));
    SetNotifyExits("este");
    AddExit("este",Z_CIUDAD("calle_27"));
    AddDoor("este","la puerta de la zapatería",
        "Es una gruesa puerta de madera labrada, fuerte y resistente.\n",
        ({"puerta","puerta de zapateria","puerta de zapatería","puerta de la zapateria",
            "puerta de la zapatería","puerta este"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CLOSE_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CANT_OPEN_MSG:({({"Intentas abrir la puerta, y al no poder, la miras y ves "
                "un cartel:\n'Cerrado toda la noche.'\n","Tratas de abrir la puerta en "
                "la oscuridad, pero no logras encontrar la manija.\n"}),({"@nombre@ trata de "
                "entrar en la zapatería, pero se da cuenta de que cierra durante la noche.\n",
                "Oyes a alguien removerse, jurando en la oscuridad.\n"}),
                "Parece que alguien trata de abrir la puerta.\n"}),
                P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    AddArticle(PROT("zapatos_cuero"), REFRESH_REMOVE, 2);
    AddArticle(PROT("botas_cuero"), REFRESH_REMOVE, 2);
    AddArticle(PROT("sandalias_cuero"), REFRESH_REMOVE, 1);
}

init()
{
    ::init();
    if (IS_LEARNER(TP) && TP->QueryInvis()) return;
    SkSay("Hola "+NOMBRE+", bienvenid"+AO+" a mi tienda.\n");
}
