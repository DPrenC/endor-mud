/*
DESCRIPCION : libreria de Hans
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/tienda/libreria.c
MODIFICACION: 17-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/
#include "path.h"
#include AK_MACRO
#include <properties.h>
#include <materials.h>
#include <door.h>
#include <sounds.h>
#include <wizlevels.h>
#include <scheduler.h>
inherit SHOP;

create()
{
    ::create();
   SetIntShort("la librer�a de Hans");
    SetIntLong("El aire huele a papel reseco aqu�, en la librer�a de Hans. Observas como una "
        "gruesa capa de polvo recubre la mayor parte de los libros de este peque�o local, lo "
        "cu�l te da una idea bastante clara de la afici�n de los orcos por la lectura. Sin "
        "embargo, la secci�n de mapas est� pr�cticamente vac�a...\n Al fondo del local hay una "
        "gran mesa bajo la cu�l ves un brasero. Es en ese lugar donde Hans trabaja, bien "
        "copiando libros o, sobre todo, dibujando mapas.\n");
    AddDetail(({"libros"}),"�Esto es una librer�a!! Hay libros por todas partes. La mayor�a "
        "est�n cubiertos por una gruesa capa de polvo, por lo que juzgas que no deben venderse "
        "demasiado bien.\n");
    AddDetail(({"mapas"}),"Hay una secci�n de la librer�a dedicada a los mapas que Hans compra "
        "o dibuja. Est� medio vac�a lo cu�l te indica que suelen venderse f�cilmente.\n");
    AddDetail(({"mesa"}),"Al fondo de la habitaci�n hay una gran mesa de madera de roble. Es "
        "en ella donde Hans pasa la mayor parte del tiempo dibujando los mapas que luego vende.\n");
    AddDetail(({"brasero"}),"Hay un brasero bajo la mesa en la que trabaja Hans. Las brasas "
        "que contiene dan el calor necesario en las largas noches que Hans debe pasar "
        "dibujando.\n");
    AddDetail(({"tienda","local","libreria","librer�a"}),QueryIntLong());
    SetIntNoise((sk_in_shop()?0:"El �nico sonido es el de Hans dibujando sobre pergamino.\n"));
    SetIntSmell("Huele a papel y a polvo.\n");
    SetLocate("ciudad de Zarkam");
    SetIndoors(1);
    SetIntBright(50);
    CanSell(0);     //El cliente no puede vender a la tienda
    CanAppraise(0); //No se valoran objetos
    CanIdentify(0); //No se identifican objetos
    RemoveDustbin();
    SetShopkeeper(PNJ_Z_CIUDAD("hans"));
    SetLastDest(Z_CIUDAD("calle_16"));
    SetNotifyExits("este");
    AddExit("este",Z_CIUDAD("calle_16"));
    AddDoor("este","la puerta de la librer�a",
        "Es una gruesa puerta de madera labrada, fuerte y resistente.\n",
        ({"puerta","puerta de libreria","puerta de librer�a","puerta de la libreria",
            "puerta de la librer�a"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CLOSE_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CANT_OPEN_MSG:({({"Intentas abrir la puerta, y al no poder, la miras y ves "
                "un cartel:\n'Cerrado toda la noche.'\n","Tratas de abrir la puerta en "
                "la oscuridad, pero no logras encontrar la manija.\n"}),({"@nombre@ trata de "
                "entrar en la librer�a, pero se da cuenta de que cierra durante la noche.\n",
                "Oyes a alguien removerse, jurando en la oscuridad.\n"}),
                "Parece que alguien trata de abrir la puerta.\n"}),
                P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    AddArticle("/obj/calendario/calendario_daggerfall", REFRESH_REMOVE, 1);
    AddArticle(MAPA("valle_zarkam"), REFRESH_REMOVE, 2);
    //AddArticle(LIBRO(""), REFRESH_REMOVE, 1);
}

init()
{
    ::init();
    if (IS_LEARNER(TP) && TP->QueryInvis()) return;
    SkSay("Hola "+NOMBRE+", bienvenid"+AO+" a mi tienda.\n");
}
