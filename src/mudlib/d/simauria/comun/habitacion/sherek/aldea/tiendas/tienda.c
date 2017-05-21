/* Archivo: /d/simauria/comun/habitacion/abadia/aldea/tienda.c
* Descripci�n: Tienda de la aldea de Sloch.
* Autor: Lug y Yalin.
*/
#include "path.h"
#include <wizlevels.h>
#include <properties.h>
#include <materials.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
inherit SHOP;

create()
{
    ::create();
    SetLocate("la aldea de Sloch");
    SetIntShort("la tienda de Loysha");
    SetIntLong("La �nica tienda de Sloch no es m�s que un cuartucho peque�o "
        "adosado a la taberna.\nEst� regentada por Loysha, la mujer del "
        "tabernero.\nAqu� puedes encontrar art�culos de utilidad para una "
        "emergencia en tu camino, pero no busques nada sofisticado, no es "
        "�sta aldea para lujos.\n");
    SetIndoors(1);
    SetIntBright(50);
    SetIntSmell("Huele a tenducho de pueblo: metal, cuero y algo de comida.\n");
    SetIntNoise("Llega el ambiente lejano de la taberna.\n");
    AddDetail(({"articulo","art�culo","articulos","art�culos","mercancia","mercanc�a","mercancias","mercanc�as"}),
        "Las mercanc�as est�n ordenadas sobre las estanter�as. Si quieres "
        "saber lo que puedes comprar, ser� mejor que pidas la lista.\n");
    AddDetail(({"estanteria","estanter�a","estanterias","estanter�as","estante","estantes"}),
        "Los estantes est�n adosados a la pared, y contienen la mercanc�a "
        "que se ofrece en la tienda.\n");
    SetShopkeeper(PNJ("sherek/aldea/loysha"));
    SetLastDest("taberna");
    SetNotifyExits("oeste");
    SetInformCloseMsg("Loysha se asoma a la taberna y grita: �Tabur!, prep�rame algo de comida "
        "para llevar a casa, voy a cerrar ya.\n");
    SetThrowOutMsg("Loysha dice: Bueno, por hoy ya est� bien, me voy a casa. Si tienes la "
        "bondad de salir...\n");
    SetNotifyCloseMsg("Loysha sale de la tienda, cierra la puerta y echa la llave. Luego "
        "coge la fuente con comida que Tabur le ha dejado en el mostrador, y desaparece por "
        "el oeste.\n");
    AddExit("oeste",SHERALD("tiendas/taberna"));
    AddDoor("oeste","la puerta de la tienda",
        "La puerta no es muy gruesa. Est� hecha de madera pulida. En su parte superior tiene "
            "un panel de cristal. Al ser interior, no es m�s que una simple puerta.\n",
        ({"puerta","puerta oeste","puerta de tienda","puerta de la tienda"}),GENDER_FEMALE,
        ([P_DOOR_TRANSPARENCY:1,P_MATERIAL:M_MADERA,P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT,
            P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CLOSE_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CANT_OPEN_MSG:({({"Cuando vas a abrir la puerta, ves a trav�s del cristal "
                "que no hay nadie dentro, ni siquiera tendero, por lo que deduces que est� "
                "cerrada.\n","En esta oscuridad no consigues encontrar ninguna puerta.\n"}),
                ({"@nombre@ pretende entrar en la tienda, pero se la encuentra cerrada.\n",
                "Oyes a alguien moverse a tu alrededor en medio de las tinieblas.\n"}),
                "Alguien trata de abrir la puerta.\n"})]));
    AddArticle(ARMA("vara"), REFRESH_REMOVE,3);
    AddArticle(OTRO("cuerda"), REFRESH_REMOVE,3);
    AddArticle("/obj/torch", REFRESH_REMOVE,4);
    AddArticle("/obj/lighter", REFRESH_REMOVE, d2());
    AddArticle("/obj/oil_bottle",REFRESH_REMOVE,3);
    AddArticle("/obj/vialv",REFRESH_REMOVE,5);
    AddArticle("/obj/vialm",REFRESH_REMOVE,5);
    AddArticle("/obj/vial",REFRESH_REMOVE,3);
    AddArticle("/obj/mochila",REFRESH_REMOVE,4);
    AddArticle(OTRO("mochilac"),REFRESH_REMOVE,2);
    AddArticle("/obj/bcocina", REFRESH_REMOVE,3);
    AddArticle("/obj/candle", REFRESH_REMOVE,d3());
}

init()
{
    ::init();
    if (IS_LEARNER(TP) && TP->QueryInvis()) {}
    else SkSay("Hola "+TNAME+", bienvenid"+(TP->QueryGenderEndString())+" a mi tienda.\n");
}
