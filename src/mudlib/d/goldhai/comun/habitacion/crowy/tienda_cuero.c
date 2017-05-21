/********************
Fichero: tienda_cuero.c
Autor: Lug y Yalin
Descripci�n: tienda de art�culos de cuero.
fecha: 20/08/2007.
********************/
#include "./path.h"
#include <properties.h>
#include <wizlevels.h>
#include <door.h>
#include <nightday.h>
#include <scheduler.h>
#include <sounds.h>


inherit SHOP;

create()
{
    ::create();
    SetIntShort("un taller de cuero");
    SetIntLong("Est�s en el taller de Theull.\n "
    "En este peque�o local, el viejo Theull pasa las horas trabajando el cuero. Es "
        "un h�bil artesano, por lo que gentes de todas partes vienen a comprarle, y muchos de "
        "sus productos son comercializados por otras tiendas.\nEl local es acogedor, reducido "
        "pero limpio y bien cuidado.\nPor las paredes, perfectamente colocados y mimados, Theull "
        "expone orgulloso sus art�culos.\nTras el mostrador, una mesa se halla repleta de "
        "piezas de piel y herramientas propias del oficio del due�o.\n");
    SetIntBright(40);
    SetIntNoise("El silencio s�lo es interrumpido a intervalos por el roce de la cuchilla o el "
        "hilo al deslizarse por las pieles que Theull est� modelando.\n");
    AddDetail(({"mesa"}),"Es una robusta mesa hecha de madera maciza.\n");
    AddDetail(({"articulos","art�culos","productos","articulos de piel","art�culos de piel",
        "productos de piel"}),"Se alinean todo a lo largo de las paredes. Si quieres m�s "
        "detalles, consulta la lista.\n");
    AddDetail(({"herramientas","utensilios"}),"Son los �tiles de trabajo de Theull. Est�n sobre "
        "la mesa, lejos de tu alcance.\n");
    AddDetail(({"piezas","pieles","piezas de piel"}),"Son pieles de animales, ya curtidas o a "
        "medio curtir, con las que el artesano confecciona sus productos.\n");
    CanSell(0);
    CanAppraise(0);
    CanIdentify(0);
    RemoveDustbin();
    RemoveExit("almacen");
    SetShopkeeper(PNJ("crowy/theull"));
    AddArticle(PROT("botas_altas"), REFRESH_REMOVE);
    AddArticle(PROT("botas_lujosas"), REFRESH_REMOVE);
    AddArticle(PROT("botas_pesadas"), REFRESH_REMOVE);
    AddArticle(PROT("botines"), REFRESH_REMOVE);
    AddExit("norte",CROWY("calle12"));
    AddDoor("norte", "la puerta de la calle",
    "Es la puerta de salida que da a una de las calles de Crowy.\n",
    ({"puerta", "puerta de salida", "puerta de la calle", "puerta del norte"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"), P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    SetLastDest("./calle12");
    SetNotifyExits("norte");

}

init()
{
    ::init();
    if (IS_LEARNER(TP) && TP->QueryInvis()) {}
    else SkSay("Hola "+TNAME+", bienvenid"+(TP->QueryGender()==GENDER_FEMALE?"a":"o")+" a mi tienda.\n");
}
