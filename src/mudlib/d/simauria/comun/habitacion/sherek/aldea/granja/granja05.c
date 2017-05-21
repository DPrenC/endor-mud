/* Archivo        granja05.c
   Autor:         Yalin y Lug
   Fecha:         12/05/2006
   Descripción:   Calle de la granja de la aldea (proyecto)
*/

#include "path.h"
#include <properties.h>
#include <materials.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
inherit SHERALD("granja/granja");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al sur puedes ver una pocilga, al oeste "
        "la calle termina en una pequeña herrería, al norte hay un granero y "
        "al noroeste la entrada a unos campos de cultivo. Hacia el este "
        "continúa la calle.\n");
    SetIntNoise("Escuchas, hacia el oeste,  el golpeteo del martillo sobre "
        "el yunque.\n");
    SetIntSmell("Huele a humo.\n");
    AddDetail(({"pocilga","sur"}),"es una edificación baja, hecha de maderas, "
        "que se utiliza para criar cerdos.\n)");
    AddDetail(({"herreria","herrería","oeste"}),"es el cobertizo en el que "
        "trabaja el herrero de la granja haciendo y reparando herramientas.\n");
    AddDetail(({"granero","norte"}),"Es el granero de la granja. Se trata de "
        "una construcción de madera bastante grande que se alza del suelo "
        "apoyada en gruesos troncos para evitar que el agua o los roedores "
        "estropeen las cosechas almacenadas allí antes de que sean "
        "transportadas hasta la abadía de Sherek.\n");
    AddExit("oeste", SHERALD("tiendas/herreria"));
    AddExit("este", SHERALD("granja/granja04"));
    AddExit("norte", SHERALD("granja/granero01"));
    AddExit("sur", SHERALD("granja/pocilga"));
    AddExit("noroeste", SHERALD("campo/labranza16"));
    AddDoor("oeste","la puerta de la herrería",
        "Es una puerta de hierro. No es que nadie vaya a intentar robar aquí, pero "
            "probablemente el herrero se ha hecho él mismo la puerta, y él mismo la repare, "
            "cuestión de economía...\n",
        ({"puerta","puerta oeste","puerta de herrería","puerta de la herrería"}),GENDER_FEMALE,
        ([P_MATERIAL:M_HIERRO,P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT,
            P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
            P_DOOR_CLOSE_SOUND:SND_SUCESOS("cerrar_metalica"),
            P_DOOR_CANT_OPEN_MSG:({({"Cuando ves que la puerta no se abre, recuerdas que el "
                "herrero también necesita descansar...\n","Buscas una puerta que abrir, pero "
                "en la oscuridad te va a resultar imposible...\n"}),({"@nombre@ trata de "
                "entrar en la herrería, seguramente piensa que los herreros no duermen...\n",
                "Oyes que alguien se remueve furioso en las sombras...\n"}),"Parece que "
                "alguien trata de abrir la puerta...\n"})]));
    AddItem(PNJ("sherek/aldea/guardian"), REFRESH_DESTRUCT,1);
}
