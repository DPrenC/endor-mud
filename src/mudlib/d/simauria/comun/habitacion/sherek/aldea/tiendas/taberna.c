/* Archivo: /d/simauria/comun/habitacion/abadia/aldea/taberna.c
* Descripción: La taberna El Labriego Cansado.
* Autor: Lugy Yalin.
*/

#include "path.h"
#include <properties.h>
#include <nightday.h>
#include <materials.h>
#include <scheduler.h>
#include <door.h>
#include <sounds.h>
inherit PUB;

create()
{
    ::create();
    SetLocate("la aldea de Sloch");
    SetIntShort("la taberna El Labriego Cansado");
    SetIntLong("Éste es el único sitio en la aldea donde un caminante puede "
        "parar a tomar un trago o llenar el estómago.\nEl nombre no es ajeno "
        "al lugar, ya que aquí sólo vienen por lo general los pobres "
        "campesinos, a charlar un rato antes de retirarse a sus casas, "
        "deshechos por un día de duro y continuado trabajo.\nUn intento de "
        "mostrador y 4..., podríamos llamar mesas con sus 2 sillas cada una, "
        "componen todo el mobiliario.\n");
    SetIndoors(1);
    SetIntBright(50);
    SetIntSmell("Hay un pesado olor a aceite refrito y alcohol.\n");
    SetIntNoise("El entrechocar de vasos, botellas y cubiertos, y gritos de "
        "algún borracho.\n");
    AddDetail(({"tablon","tablón","mostrador","barra"}), "Un simple tablón, "
        "apenas pulido y mal barnizado, sostenido por 4 trozos de tronco, "
        "hace las veces de mostrador de la taberna.\n");
    AddDetail(({"tronco","troncos","trozo","trozos"}), "4 trozos de tronco "
        "descortezados y cortados a medida, sostienen el tablón que sirve "
        "de mostrador.\n");
    AddDetail(({"mesa","mesas","silla","sillas"}), "Las mesas y las sillas "
        "son simples bloques de madera toscamente labrados, que cumplen "
        "ajustadamente la misión de servir de asiento y soporte para la "
        "comida.\n");
    AddDetail(({"pared","paredes","muro","muros"}), "Sólo distingues el "
        "negro amarillento de la grasa requemada y el humo del tabaco.\n");
    AddDetail(({"suelo","baldosa","baldosas","losa","losas"}), "simples "
        "baldosas de barro cocido, sin dibujos ni acabado.\n");
    SetKeeper(QUEST+"sherek/tabur");
    SetCloseTime(({ND_PREDAWN,ND_DAWN,ND_SUNRISE}));
    SetLastDest(SHERALD("calles/calle00"));
    SetNotifyExits("oeste");
    SetInformCloseMsg("Tabur comienza a recoger los vasos del mostrador diciendo: Bueno, haced "
        "el favor de terminar vuestras consumiciones, vamos a cerrar ya.\n");
    SetThrowOutMsg("Tabur arroja el trapo y el cuchillo bajo el mostrador, sale de detrás de "
        "éste y con dos palmadas dice: Está bien, todo el mundo fuera, es hora de dormir.\n");
    AddItem(PNJ("sherek/aldea/borracho"), REFRESH_DESTRUCT,1);
    AddItem(QUEST+"sherek/marath", REFRESH_DESTRUCT,1);
    AddExit("oeste", SHERALD("calles/calle00"));
    AddExit("este", SHERALD("tiendas/tienda"));
    AddDoor("oeste","la puerta de la taberna",
        "Es una vieja puerta de madera bastante estropeada, pero con la guardia patrullando la "
            "calle, no es probable que nadie intente forzarla, y por otra parte, aquí hay poco "
            "que robar.\n",
        ({"puerta","puerta oeste","puerta de taberna","puerta de la taberna"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_CLOSE_TIME:({ND_PREDAWN,ND_DAWN,ND_SUNRISE}),
            P_DOOR_CANT_OPEN_MSG:({({"La taberna está cerrada. Hasta mañana tendrás que beber "
                "en la fuente.\n","Tratas de abrir la puerta en la oscuridad, pero no "
                "encuentras la manija.\n"}),({"@nombre@ pensaba comer o beber algo, pero la "
                "taberna está cerrada.\n","Oyes a alguien removerse, jurando en la oscuridad.\n"}),
                "Parece que alguien trata de abrir la puerta.\n"})]));
    AddDoor("este","la puerta de la tienda",
        "La puerta no es muy gruesa. Está hecha de madera pulida. En su parte superior tiene "
            "un panel de cristal. Al ser interior, no es más que una simple puerta.\n",
        ({"puerta","puerta este","puerta de tienda","puerta de la tienda"}),GENDER_FEMALE,
        ([P_DOOR_TRANSPARENCY:1,P_MATERIAL:M_MADERA,P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT,
            P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CLOSE_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CANT_OPEN_MSG:({({"Cuando vas a abrir la puerta, ves a través del cristal "
                "que no hay nadie dentro, ni siquiera tendero, por lo que deduces que está "
                "cerrada.\n","En esta oscuridad no consigues encontrar ninguna puerta.\n"}),
                ({"@nombre@ pretende entrar en la tienda, pero se la encuentra cerrada.\n",
                "Oyes a alguien moverse a tu alrededor en medio de las tinieblas.\n"}),
                "Alguien trata de abrir la puerta.\n"})]));
    AddFood("cerdo","un trozo de",12,11,0);
    AddFood("estofado de ternera","un plato de",9,12,0);
    AddFood("pollo con patatas","un plato de",10,15,0);
    AddFood("sopa de verduras","un plato de",7,8,0);
    AddDrink("cerveza","una jarra de",3,4,8,0);
    AddDrink("vino","un vaso de",10,10,5,0);
    AddDrink("aguardiente","un vaso de",20,20,10,0);
}
