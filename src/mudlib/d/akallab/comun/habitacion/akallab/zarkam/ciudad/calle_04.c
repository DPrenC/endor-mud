/*
DESCRIPCION : calle mayor de Zarkam
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_04.c
MODIFICACION: 12-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
inherit ROOM;

create()
{
    ::create();
    SetIntShort("la calle mayor de Zarkam");
    SetIntLong("Te encuentras en la calle mayor de Zarkam. Esta calle es la más importante de "
        "la ciudad a la que recorre de norte a sur. Al este de aquí se halla un gran edificio "
        "de tres plantas. Esta sobria construcción de piedra, desde la que te llega sonido de "
        "lucha, es la sede local del 'Gremio de Guerreros'. Observas que en el bajo del "
        "edificio que queda al oeste se halla una tienda.\n");
    AddDetail(({"tienda"}),"En el bajo del edificio que queda al oeste se halla una pequeña "
        "tienda. Seguro que allí se pueden encontrar los más variados productos.\n");
    AddDetail(({"gremio","Gremio","gremio de guerreros"}),"Es el alto y sobrio edificio de "
        "tres plantas que se encuentra al este de aquí.\n");
    SetIntNoise("Se oye el ajetreo típico de una ciudad.\n");
    SetIntSmell("Hmm..., el aire es más bien frío por la altura.\n");
    SetLocate("ciudad de Zarkam");
    SetIndoors(0);
    AddExit("norte",Z_CIUDAD("calle_05"));
    AddExit("oeste",Z_TIENDA("tienda00"));
    //AddExit("este",Z_GREMIO("/guerrero/entrada"));
    AddExit("sur",Z_CIUDAD("plaza_01"));
    AddDoor("oeste","la puerta de la tienda",
        "Es una gruesa puerta de madera labrada, fuerte y resistente.\n",
        ({"puerta","puerta este","puerta de tienda","puerta de la tienda"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CLOSE_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CANT_OPEN_MSG:({"Intentas abrir la puerta, y al no poder, la miras y ves un "
                                 "cartel:\n'Cerramos toda la noche'\n",(:capitalize(TP->QueryName())+
                " trata de entrar en la tienda, pero se da cuenta de que cierra durante la "
                "noche.\n":),"Oyes a alguien intentando abrir una puerta.\n"}),
                P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
}
