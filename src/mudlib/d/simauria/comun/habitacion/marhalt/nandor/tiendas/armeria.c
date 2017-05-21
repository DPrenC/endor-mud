/****************************************************************************
Fichero: armeria.c
Autor: Ratwor
Fecha: 04/11/2006
Descripción: la armería de nandor, solo se venden y compran armas.
****************************************************************************/

#include "./path.h"
#include <gremios.h>
#include <sounds.h>
#include <door.h>
#include <scheduler.h>

inherit SHOP;

//Todo está un 15% más barato para guerreros.
public int ModifyPrice(object ob, int price, string verb)
{
    if (TP->QueryGuild()!=GC_GUERREROS) return ::ModifyPrice(ob, price, verb);
    return (::ModifyPrice(ob, price, verb)*85)/100;
}

create(){
    ::create();

    SetIntBright(25);
    SetLocate("Aldea de Nandor");
    SetIntShort("la armería del buen guerrero");
    SetIntLong("Una amplia estancia se abre ante tí con una sorprendente exposición de "
        "armas de distintos tipos.\n Un buen negocio teniendo en cuenta la proximidad "
        "a la sede central del gremio de guerreros.\n  Pregunta por la lista a ver si "
        "tienen alguna buena pieza para tus aventuras, dicen que a los guerreros les hacen descuento.\n");
    AddDetail(({"armas","arma"}), "Ves armas de distintos tipos, algunas es posible que "
        "estén de adorno formando parte de la colección personal del armero, pero pregunta"
        " por la lista a ver cuales están a la venta.\n");
    AddExit("oeste", MARH("nandor/calle16"));
    RemoveExit("almacen");
    SetShopkeeper(PNJ("marhalt/armero_nandor"));
    SetNotifyExits("oeste");
    SetLastDest("../calle16");
    AddDoor("oeste", "la puerta de la calle",
    "Es la puerta que da a la calle.\n",
    ({"puerta de la calle", "puerta del oeste", "puerta"}),
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));

    if (d3()==1)
        AddArticle(ARMA("maza_hierro_p"),REFRESH_REMOVE,1);
    if (d3()==1)
        AddArticle(ARMA("yatagan"),REFRESH_REMOVE,1);
    if (d3()==1)
        AddArticle(ARMA("mangual_pesado"),REFRESH_REMOVE,1);
    if (d3()==1)
        AddArticle(ARMA("zaghnal"),REFRESH_REMOVE,1);
    if (d3()==1)
        AddArticle(ARMA("berdiche"),REFRESH_REMOVE,1);
    if (d3()==1)
        AddArticle(ARMA("claymore"),REFRESH_REMOVE,1);
    if (d3()==1)
        AddArticle(ARMA("kriss"),REFRESH_REMOVE,1);
    if (d3()==1)
        AddArticle(ARMA("maza_pinchos"),REFRESH_REMOVE,1);
    if (d4()==1)
        AddArticle("/obj/armas/arpon", REFRESH_REMOVE, 1);
    if (d4()==1)
        AddArticle("/obj/armas/cadena_armada", REFRESH_REMOVE, 1);
    if (d3()==1)
        AddArticle("/obj/armas/estilete", REFRESH_REMOVE,1);
    if(d4()==1)
        AddArticle(ARMANANDOR("espada_1mano"), REFRESH_REMOVE);
}

//solo compra armas.
int CheckTrade(object ob){
    if (ob->QueryWeaponType()) return 1;
    return 0;
}
