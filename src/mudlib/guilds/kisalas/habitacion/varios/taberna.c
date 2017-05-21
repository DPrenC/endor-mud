/****************************************************************************
Fichero: taberna.c
Autor: Riberales
Fecha: 14/02/2006
Descripci�n: Taberna de las Kisalas, remodelada.
****************************************************************************/


#include "path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
inherit PUB;

create()
{
    ::create();
    SetIntShort("la taberna de las Kisalas");
    SetIntLong("Est�s en el interior de la taberna de las Kisalas, en ella "
               "podr�s saciar tu hambre y tu sed, y, por qu� no, divertirte "
               "un poco. Se trata de un amplio local, con algunas "
               "mesas colocadas ordenadamente por toda la estancia. La verdad "
               "es que para tratarse de una taberna, transmite "
               "una cierta sensaci�n de sobriedad que no termina de encajar "
               "con el estereotipo de estos lugares.\n");

    AddDetail(({"barra"}),
                "Es una t�pica barra de taberna, pero bastante m�s ordenada "
                "y limpia que las que puedes encontrar por Simauria.\n");

    AddDetail(({"mesas","mesa"}),
              "Son unas mesas bastante grandes, de madera. Parece que la "
              "encargada del sitio no escatima tiempo en la limpieza... Sin "
              "lugar a dudas, son las mesas de tabernas con menos rallones y "
              "mugre que hayas visto jam�s.\n");
    SetIntSmell("Hueles el delicioso aroma de comida reci�n hecha.\n");
    SetIntBright(45);
    AddDrink("licor de abru�os","un vaso de",4,6,3,0,
             "Sientes un reguero de fuego cayendo por tu garganta.");
    AddDrink("aguamiel","un vaso de",5,0,12,0,"Te bebes un vaso de aguamiel.");
    AddDrink("cerveza de frambuesa","una jarra de",7,5,4,0,
             "Notas el delicioso sabor de la frambuesa.");
    AddDrink("licor de las kisalas","un vaso de",5,10,6,0,"Uf, sabe a rayos.");
    AddFood("caldo de pescado","una taza de",8,14,0);
    AddFood("cordero asado","un plato de",10,18,0);
    AddFood("pulpo","un plato de",5,10,0);
    AddFood("mero ahumado","un plato de",6,10,0);
    AddFood("pastel de cerezas","una porci�n de",4,8,0);
    SetKeeper(AM_PNJ("shira"));
    SetCloseTime(S_CLOSED_AT_NIGHT);
    SetLastDest(AM_VESTIBULO("vest1"));
    SetNotifyExits(({"este"}));
    AddExit("este",AM_VESTIBULO("vest1"));
    AddDoor("este", "la puerta del vest�bulo",
        "Es la puerta que da al vest�bulo del gremio. Est� hecha de madera con un panel de "
            "cristal en la parte superior.\n",
        ({"puerta","puerta del vest�bulo","puerta del vestibulo","puerta este"}),GENERO_FEMENINO,
        ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
        P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
        P_DOOR_TRANSPARENCY:1,P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT]));
}
