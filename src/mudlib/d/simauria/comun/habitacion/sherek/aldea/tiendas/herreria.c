/* Archivo: /d/simauria/comun/habitacion/abadia/granja/herreria.c
* Descripción: Herrería en la granja de la aldea.
* Autor: Lug y Yalin.
*/
#include "path.h"
#include <attributes.h>
#include <properties.h>
#include <skills.h>
#include <materials.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
inherit "/room/herreria";

create()
{
    ::create();
    SetLocate("la aldea de Sloch");
    SetIntShort("la herrería");
    SetIntLong("Ésta es la herrería de la aldea.\nEstá situada en la granja, "
        "pues principalmente se atienden aquí las necesidades del trabajo "
        "propio de esta aldea: venta y reparación de herramientas y herrado "
        "de animales de tiro y carga.\nA lo largo de las paredes se alinean "
        "los útiles de trabajo que los aldeanos suelen comprar aquí.\nEn un "
        "rincón puedes ver el yunque junto con un enorme martillo.\n");
    SetIndoors(1);
    SetIntBright(65);
    SetIntSmell("Huele a humo y metal recalentado.\n");
    SetIntNoise("Suena el martilleo del herrero sobre alguna pieza que esté "
        "arreglando.\n");
    AddDetail(({"pared","paredes"}), "Están asquerosamente tiznadas de humo. "
        "No te acerques demasiado.\n");
    AddDetail(({"utiles","útiles","herramientas","aperos"}), "Si quieres "
        "saber lo que puedes comprar, será mejor que pidas la lista.\n");
    AddDetail(({"yunque"}), "Es un monstruoso bloque de hierro macizo de unos "
        "1200 kilos de peso.\nSirve para colocar encima las piezas que se "
        "van a moldear a martillazos.\n");
    AddDetail(({"martillo"}), "Un mango grueso de madera con un gran prisma "
        "cuadrangular de hierro atravesado en uno de sus extremos.\n");
    AddDetail(({"suelo"}), "Está totalmente cubierto de ceniza y virutas de "
        "metal.\n");
    AddDetail(({"viruta","virutas","ceniza"}), "La ceniza de la fragua y las "
        "virutas de metal cubren todo el suelo.\n");
    AddDetail(({"fuego","fragua"}), "El fuego es tan fuerte que te impide "
        "ver lo que se está calentando en la fragua.\n");
    SetShopkeeper(PNJ("sherek/aldea/mathin"));
    SetLastDest(SHERALD("granja/granja05"));
    SetNotifyExits("este");
    SetInformCloseMsg("Mathin suelta el martillo y corta la ventilación de la fragua, lo que te "
        "indica claramente que se dispone a cerrar la herrería.\n");
    AddArticle(OTRO("sherek/aldea/azada"),REFRESH_REMOVE,3);
    AddArticle(OTRO("sherek/aldea/azadon"),REFRESH_REMOVE,3);
    AddArticle(OTRO("sherek/aldea/pico"),REFRESH_REMOVE,3);
    AddArticle(OTRO("sherek/aldea/rastrillo"),REFRESH_REMOVE,3);
    AddArticle(OTRO("sherek/aldea/guadanya"),REFRESH_REMOVE,3);
    AddExit("este", SHERALD("granja/granja05"));
    AddDoor("este","la puerta de la herrería",
        "Es una puerta de hierro. No es que nadie vaya a intentar robar aquí, pero "
            "probablemente el herrero se ha hecho él mismo la puerta, y él mismo la repare, "
            "cuestión de economía...\n",
        ({"puerta","puerta este","puerta de herrería","puerta de la herrería"}),GENDER_FEMALE,
        ([P_MATERIAL:M_HIERRO,P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT,
            P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
            P_DOOR_CLOSE_SOUND:SND_SUCESOS("cerrar_metalica"),
            P_DOOR_CANT_OPEN_MSG:({({"Cuando ves que la puerta no se abre, recuerdas que el "
                "herrero también necesita descansar...\n","Buscas una puerta que abrir, pero "
                "en la oscuridad te va a resultar imposible...\n"}),({"@nombre@ trata de "
                "entrar en la herrería, seguramente piensa que los herreros no duermen...\n",
                "Oyes que alguien se remueve furioso en las sombras...\n"}),"Parece que "
                "alguien trata de abrir la puerta...\n"})]));
}
