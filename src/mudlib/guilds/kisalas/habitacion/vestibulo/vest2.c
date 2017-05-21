/****************************************************************************
Fichero: vest2.c
Autor: Riberales
Fecha: 14/02/2006
Descripción: Vestíbulo de las Kisalas. Remodelación espacial total.
Notas: [R] No tiene ni fecha, así es que le pongo la de hoy.
****************************************************************************/


#include "path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
inherit INTERIOR_BASE;

create()
{
    ::create();
    SetIntShort("el vestíbulo del Gremio de las Kisalas");
    SetIntLong("Te encuentras en una parte del enorme vestíbulo del Gremio de "
               "las Kisalas. Por las paredes hay numerosos grabados y "
               "bajorelieves que representan la vida cotidiana y la historia "
               "de éstas. En la piedra del suelo hay tallado un sello con el "
               "símbolo de las Kisalas. La luz de la estancia proviene de las "
               "espirales fosforescentes situadas en el techo. Al Norte y "
               "noroeste, el vestíbulo continúa, al Oeste está la salida del "
               "Gremio y al Este hay una pequeña herrería.\n");


    AddDetalleRelieves();
    AddDetalleGrabados();

    AddExit("norte",AM_VESTIBULO("vest5"));
    AddExit("noroeste",AM_VESTIBULO("vest4"));
    AddExit("este",AM_VARIOS("herreria"));
    AddExit("oeste",AM_ROOM("entrada"));
    AddDoor("este","la puerta de la herrería",
        "Es una puerta de hierro. No es que nadie vaya a intentar robar aquí, pero "
            "probablemente Dana se haya hecho ella misma la puerta, y ella misma la repare, "
            "cuestión de economía...\n",
        ({"puerta","puerta este","puerta de herrería","puerta de la herrería",
            "puerta de herreria","puerta de la herreria"}),GENDER_FEMALE,
        ([P_MATERIAL:M_HIERRO,P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT,
            P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
            P_DOOR_CLOSE_SOUND:SND_SUCESOS("cerrar_metalica"),
            P_DOOR_CANT_OPEN_MSG:({({"Cuando ves que la puerta no se abre, recuerdas que la "
                "herrera también necesita descansar...\n","Buscas una puerta que abrir, pero "
                "en la oscuridad te va a resultar imposible...\n"}),({"@nombre@ trata de "
                "entrar en la herrería, seguramente piensa que las kisalas no duermen...\n",
                "Oyes que alguien se remueve furioso en las sombras...\n"}),"Parece que "
                "alguien trata de abrir la puerta...\n"})]));
}
