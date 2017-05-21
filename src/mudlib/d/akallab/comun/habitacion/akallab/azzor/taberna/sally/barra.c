 /*
DESCRIPCION : en la taberna de Sally la gorda el puerto de Azzor
FICHERO     : /d/akallab/comun/habitación/akallab/azzor/taberna/sally/barra.c
MODIFICACION: 08-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
#include <properties.h>
#include <nightday.h>
#include <door.h>
#include <sounds.h>
inherit PUB;

create()
{
    ::create();
    SetIntShort("la barra de la taberna de Sally la gorda");
    SetIntLong("Estás junto a la barra de la taberna de Sally la gorda, una de las más famosas "
        "de la ciudad. Sally, que debe andar por aquí, es una orca con fama de descarada, "
        "pendenciera, juerguista, ladrona y muchas otras cosas más.\nLa taberna es un local de "
        "mediano tamaño con varios arcos que sostienen su bajo techo. A tu lado se encuentra "
        "la barra donde pedir un trago, y al norte, mesas para sentarse.\nAl oeste se ve una "
        "escalera, y al este tienes la puerta de la calle.\n");
#include "taberna_detail.h"
    SetKeeper(PNJ_AZZOR("nytjar"));
    // Cerramos al alba y abrimos por la tarde, es para juerguistas
    SetCloseTime(({ND_DAWN,ND_SUNRISE,ND_PRENOON,ND_DAY}));
    SetAssociatedRooms(({"mesas","rincon","escalera0","escalera1","cocina","pasillo",
        "habitacion0","habitacion1","trastero"}));
    SetLastDest(AZ_PUERTO("portico05"));
    SetThrowOutMsg("Sally grita desde el escenario: Nytjar, me voy, cierra ya.\nNitjar sale de "
        "detrás del mostrador, agitando los puños y gritando: ¡Fuera todos! ¡A dormir la mona "
        "a vuestros barcos! ¡Fuera, fuera!\n");
    SetNotifyExits("este");
    SetInformCloseMsg("Al este oyes a Sally gritar: Nytjy, bonita, vamos a ir cerrando ya, ¿no "
        "te parece?.\nSorprendes una mirada furtiva de Nytjar hacia el rincón, luego golpea el "
        "mostrador con un vaso y grita: ¡Ya lo habéis oído, mostrencos! Id vaciando esos "
        "vasos, y ¡a la calle a tomar el aire!\n");
    SetNotifyOpenMsg("Nytjar abre la puerta, se asoma y grita: ¡Está bien, dejad de vociferar, "
        "ya podéis entrar a emborracharos, patanes!, y sin mirarte siquiera, se mete tras el "
        "mostrador.\n");
    SetNotifyCloseMsg("El último borracho sale dando traspiés, perseguido por los puños de "
        "Nytjar, quien asoma la cabeza gritando: ¡Y cuidado con armar bronca! Si me hacéis "
        "bajar os váis a acordar de este día toda vuestra vida. Y con un descomunal bostezo, "
        "se mete en la taberna y cierra la puerta de un golpe.\n");
    AddExit("norte","mesas");
    AddExit("oeste","escalera0");
    AddExit("este",AZ_PUERTO("portico05"));
    AddDoor("este","la puerta de la taberna",
        "Es una gruesa puerta de madera, barnizada y decorada, elegante , pero resistente.\n",
        ({"puerta","puerta taberna","puerta de taberna","puerta de la taberna"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_CLOSE_TIME:({ND_DAWN,ND_SUNRISE,ND_PRENOON,ND_DAY}),
            P_DOOR_CANT_OPEN_MSG:({({"La taberna cierra al alba, y abrirá por la tarde, espera "
                "un poco para emborracharte...\n","Buscas la puerta en la oscuridad, pero no "
                "logras encontrarla... Cuidado al moverte, no vayas a caerte al mar.\n"}),
                ({"@nombre@ pensaba meterse un lingotazo, pero la taberna está cerrada...\n",
                "Oyes a alguien rebuscar, jurando en la oscuridad.\n"}),
                "Parece que alguien trata de abrir la puerta.\n"})]));
    //nombre,articulo,vida,alcohol,sed,valor,mensaje
    AddDrink("cerveza rubia","una",3,5,2,0,"Te bebes una cerveza rubia, clara y amarga.");
    AddDrink("cerveza negra","una",3,4,3,0,"Te bebes una cerveza oscura, espesa y de sabor fuerte.");
    AddDrink("cerveza de trigo","una",3,3,3,0,"Te bebes una cerveza muy clara y de sabor suave.");
    AddDrink("cerveza hefe","una",3,4,3,0,"Te bebes una cerveza oscura, espesa, espumosa y ligeramente amarga.");
    AddDrink("cerveza koelsch","una",3,4,2,0,"Te bebes una cerveza rubia, espesa y amarga.");
    AddDrink("cerveza de frutas","una",3,2,3,0,"Te bebes una cerveza con trozos de fruta y de sabor dulzon.");
    AddDrink("vino","una jarra de",4,6,3,0,"Apuras una buena jarra de vino tibio.");
    AddDrink("vino rancio","un vaso de",1,5,1,0,"Uarrgghh.. esta asqueroso.");
    AddDrink("gluhwein","un vaso de",2,4,2,0,"Saboreas un aromatico vino caliente con especias.");
    AddDrink("grog","una jarra de",3,8,4,0);
    AddDrink("ron","un vaso de",1,7,2,0);
    AddDrink("whisky","un vaso de",1,7,2,0);
    AddDrink("orujo","un vaso de",3,10,1,0, "Notas como el orujo te va quemando la garganta lentamente.");
    AddItem(PNJ_AZZOR("druj"),REFRESH_DESTRUCT);
}
