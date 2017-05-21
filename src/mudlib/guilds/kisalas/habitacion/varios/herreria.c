/*=============================================================*
 |            << GOLDHAI.Gremio [w] Woo@simauria >>            |
 *=============================================================*
 |               Creacion.............. 02-12-99               |
 |               Ultima Modificacion... 02-12-99               |
 |                                                             |
 *=============================================================*/

#include "path.h"
#include <guild.h>
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
#include <rooms.h>
inherit SMITHY;

create()
{
    ::create();
    SetIntShort("la armer�a del Gremio de Kisalas");
    SetIntLong("Est�s dentro de la armer�a de la orden de las Kisalas, una "
               "herrer�a de decoraci�n muy austera y simple. Aqu� podr�s "
               "comprar nuevas armas o pedir que te reparen las que con el "
               "uso, se han ido desgastando. Si miras bien ver�s que los "
               "precios son bastante m�s econ�micos, aunque solo para las que "
               "pertenecen a la orden.\n");
    SetIndoors(1); // 1: A cubierto  0: A descubierto
    SetIntBright(45);
    SetIntNoise("No oyes nada especial.\n");
    SetIntSmell("Hueles a hierro candente.\n");
    SetSmithy(0);
    SetShopkeeper(AM_PNJ("danna"));
    AddArticle(ARMA_GOLDHAI("vara"),REFRESH_REMOVE,5);
    AddArticle(ARMA_GOLDHAI("vara_metal"),REFRESH_REMOVE,      5);
    AddArticle(ARMA_GOLDHAI("abanico"),REFRESH_REMOVE,5);
    AddArticle(ARMA_GOLDHAI("hacha_combate"),REFRESH_REMOVE,5);
    AddArticle("/obj/carcaj",REFRESH_REMOVE,5);
    AddArticle(PROT_GOLDHAI("escudo_madera"),REFRESH_REMOVE,5);
    AddArticle("/obj/arco",REFRESH_REMOVE,5);
    SetLastDest(AM_VESTIBULO("vest2"));
    SetNotifyExits(({"oeste"}));
    AddExit("oeste",AM_VESTIBULO("vest2"));
    AddDoor("oeste","la puerta del vest�bulo",
        "Es una puerta de hierro. No es que nadie vaya a intentar robar aqu�, pero "
            "probablemente Dana se haya hecho ella misma la puerta, y ella misma la repare, "
            "cuesti�n de econom�a...\n",
        ({"puerta","puerta oeste","puerta de vest�bulo","puerta del vest�bulo",
            "puerta de vestibulo","puerta del vestibulo"}),GENDER_FEMALE,
        ([P_MATERIAL:M_HIERRO,P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT,
            P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
            P_DOOR_CLOSE_SOUND:SND_SUCESOS("cerrar_metalica"),
            P_DOOR_CANT_OPEN_MSG:({({"Cuando ves que la puerta no se abre, recuerdas que la "
                "herrera tambi�n necesita descansar...\n","Buscas una puerta que abrir, pero "
                "en la oscuridad te va a resultar imposible...\n"}),({"@nombre@ trata de "
                "entrar en la herrer�a, seguramente piensa que las kisalas no duermen...\n",
                "Oyes que alguien se remueve furioso en las sombras...\n"}),"Parece que "
                "alguien trata de abrir la puerta...\n"})]));
    SetLocate("el gremio de las Kisalas");
}

int ModifyPrice(object ob,int price,string verb)
{
    if (TP->QueryGuild()==GC_KISALAS)
    {
        if (verb=="comprar") return price - (price/3);
    }
    return price;
}
