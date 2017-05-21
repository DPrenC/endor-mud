/* Archivo        granja05.c
   Autor:         Yalin y Lug
   Fecha:         12/05/2006
   Descripci�n:   Calle de la granja de la aldea (proyecto)
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
        "la calle termina en una peque�a herrer�a, al norte hay un granero y "
        "al noroeste la entrada a unos campos de cultivo. Hacia el este "
        "contin�a la calle.\n");
    SetIntNoise("Escuchas, hacia el oeste,  el golpeteo del martillo sobre "
        "el yunque.\n");
    SetIntSmell("Huele a humo.\n");
    AddDetail(({"pocilga","sur"}),"es una edificaci�n baja, hecha de maderas, "
        "que se utiliza para criar cerdos.\n)");
    AddDetail(({"herreria","herrer�a","oeste"}),"es el cobertizo en el que "
        "trabaja el herrero de la granja haciendo y reparando herramientas.\n");
    AddDetail(({"granero","norte"}),"Es el granero de la granja. Se trata de "
        "una construcci�n de madera bastante grande que se alza del suelo "
        "apoyada en gruesos troncos para evitar que el agua o los roedores "
        "estropeen las cosechas almacenadas all� antes de que sean "
        "transportadas hasta la abad�a de Sherek.\n");
    AddExit("oeste", SHERALD("tiendas/herreria"));
    AddExit("este", SHERALD("granja/granja04"));
    AddExit("norte", SHERALD("granja/granero01"));
    AddExit("sur", SHERALD("granja/pocilga"));
    AddExit("noroeste", SHERALD("campo/labranza16"));
    AddDoor("oeste","la puerta de la herrer�a",
        "Es una puerta de hierro. No es que nadie vaya a intentar robar aqu�, pero "
            "probablemente el herrero se ha hecho �l mismo la puerta, y �l mismo la repare, "
            "cuesti�n de econom�a...\n",
        ({"puerta","puerta oeste","puerta de herrer�a","puerta de la herrer�a"}),GENDER_FEMALE,
        ([P_MATERIAL:M_HIERRO,P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT,
            P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
            P_DOOR_CLOSE_SOUND:SND_SUCESOS("cerrar_metalica"),
            P_DOOR_CANT_OPEN_MSG:({({"Cuando ves que la puerta no se abre, recuerdas que el "
                "herrero tambi�n necesita descansar...\n","Buscas una puerta que abrir, pero "
                "en la oscuridad te va a resultar imposible...\n"}),({"@nombre@ trata de "
                "entrar en la herrer�a, seguramente piensa que los herreros no duermen...\n",
                "Oyes que alguien se remueve furioso en las sombras...\n"}),"Parece que "
                "alguien trata de abrir la puerta...\n"})]));
    AddItem(PNJ("sherek/aldea/guardian"), REFRESH_DESTRUCT,1);
}
