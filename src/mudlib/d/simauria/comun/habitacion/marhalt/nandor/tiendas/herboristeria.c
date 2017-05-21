/****************************************************************************
Fichero: herboristeria.c
Autor: Ratwor
Fecha: 04/11/2006
Descripción: la herboristeria de nandor. Sólo se comercia con hierbas y flores.
****************************************************************************/

#include "./path.h"
#include <sounds.h>
#include <door.h>
#include <scheduler.h>
inherit SHOP;

create(){
    ::create();

    SetIntBright(25);
    SetLocate("Aldea de Nandor");
    SetIntShort("la herboristería 'Flor del norte'");
    SetIntLong("Mirando alrededor no cabe duda de las características del lugar, Todo "
        "tipo de hierbas y flores te rodean.\n");
    SetShopkeeper(PNJ("marhalt/herbolario_nandor"));
    SetIntSmell("Una fuerte, aunque agradable esencia entra por tus fosas nasales.\n");
    AddDetail(({"estantería","estanterías"}),
        "Están llenas de todo tipo de hierbas y flores.\n");
    AddDetail(({"hierbas","hierba","flores","flor"}), "Son bonitas, algunas extrañas, "
        "pregunta por la lista para saber si se venden y por cuanto.\n");
    AddExit("sur", MARH("nandor/calle10"));
    RemoveExit("almacen");
    SetNotifyExits("sur");
    SetLastDest("../calle10");
    AddDoor("sur", "la puerta de la calle",
    "Es la puerta que da a la calle.\n",
    ({"puerta de la calle", "puerta del sur", "puerta"}),
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));

    AddArticle(OTRO("marhalt/nandor/flor"), REFRESH_REMOVE, d3());
    // le pongo el dx() a los artículos para que no siempre salga de todo.
    if (d3()==1)
        AddArticle(HERBS("hierba_saciante"), REFRESH_REMOVE);
    if (d3()==1)
        AddArticle(HERBS("hierba_magica"), REFRESH_REMOVE);
    if (d3()==1)
        AddArticle(HERBS("hierba_curativa"), REFRESH_REMOVE);
    if (d3()==1)
        AddArticle(HERBS("hierba_narcotica"), REFRESH_REMOVE);
    if (d3()==1)
        AddArticle(HERBS("hierba_intoxicante"), REFRESH_REMOVE);
    if (d3()==1)
        AddArticle(HERBS("seta_saciante"), REFRESH_REMOVE);
    if (d3()==1)
        AddArticle(HERBS("seta_magica"), REFRESH_REMOVE);
    if (d3()==1)
        AddArticle(HERBS("seta_curativa"), REFRESH_REMOVE);
    if (d3()==1)
        AddArticle(HERBS("seta_narcotica"), REFRESH_REMOVE);
    if (d3()==1)
        AddArticle(HERBS("seta_intoxicante"), REFRESH_REMOVE);

}

int CheckTrade(object ob){
    if (ob->id("hierba") || ob->id("flor") || ob->id("seta")) return 1;
    return 0;
}
