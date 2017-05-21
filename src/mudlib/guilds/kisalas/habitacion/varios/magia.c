/****************************************************************************
Fichero: /guilds/kisalas/habitacion/varios/magia.c
Autor: Yalin
Fecha: 28/01/2008 15:53
Descripci�n: Tienda de magia y hechicer�a de kisalas
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include <guild.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
inherit SHOP;

create()
{
    ::create();
    SetIntShort("la tienda de magia y hechicer�a");
    SetIntLong("�ste es un local peque�o, de ambiente silencioso y acogedor.\nTanto el suelo "
        "como las paredes est�n recubiertas de madera pulida, lo que le da un toque de "
        "elegancia.\nUn inexplicable halo de misterio parece impregnar todo el ambiente, y "
        "aunque no parece afectar en absoluto a las kisalas, tiende a poner bastante nerviosas "
        "a las personas ajenas al gremio, especialmente a los machos.\nAl fondo, pulcramente "
        "ordenados sobre los anaqueles, puedes ver gran variedad de vasijas de barro o cristal, "
        "y cajas de madera, cristal o piedra tallada.\n");
    AddDetail(({"frasco","caja","frascos","cajas"}),"Tanto los frascos como las cajas est�n "
        "llenos de productos que no puedes identificar, y que no deseas conocer en absoluto, "
        "aunque sospechas que son los ingredientes empleados para fabricar ung�entos, pociones "
        "y cualquier otro mejunge que puedas imaginar.\n");
    AddDetail(({"anaquel","anaqueles"}),"Son unas delgadas planchas de madera adosadas a la "
        "pared, donde se alinean toda suerte de cajas y frascos, de todas las formas, tama�os "
        "y colores posibles.\n");
    SetIndoors(1);
    SetIntBright(45);
    CanSell(0);     //No compro nada
    CanAppraise(0); //No se valoran objetos
    CanIdentify(0); //No se identifican objetos
    RemoveDustbin();
    SetShopkeeper(AM_PNJ("sylana"));
    AddExit("sur", AM_PASILLO("pasillo2"));
    AddDoor("sur", "la puerta del pasillo",
        "Es la puerta que da al pasillo. Est� hecha de madera con un panel de cristal en la "
            "parte superior.\n",
        ({"puerta","puerta del pasillo","puerta sur"}),GENERO_FEMENINO,
        ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
        P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
        P_DOOR_TRANSPARENCY:1,P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT]));
    AddArticle(AM_OBJETO("redoma"),REFRESH_REMOVE,3);
    AddArticle(AM_OBJETO("mortero"),REFRESH_REMOVE,3);
    AddArticle(AM_OBJETO("hierbas"),REFRESH_REMOVE,5);
}
 
int ModifyPrice(object ob,int price,string verb)
{
    if (TP->QueryGuild()==GC_KISALAS)
    {
        if (verb=="comprar") return price - (price/3);
    }
    return price;
}
