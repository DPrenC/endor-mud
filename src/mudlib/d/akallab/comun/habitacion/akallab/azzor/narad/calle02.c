/*
DESCRIPCION  : Calle de Narad
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/narad/calle02.c
MODIFICACION : 04-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
#include <door.h>
#include <properties.h>
#include <materials.h>
#include <sounds.h>
#include <scheduler.h>

inherit ROOM;

create()
{
    ::create();
    SetIntShort("la calle del pueblo de Narad");
    SetIntLong("Te encuentras en la esquina sudeste de la plaza del pueblo. Una calle "
        "secundaria parte desde aquí hacia el templo que queda al este. Al sur de aquí se "
        "halla una tienda.\n");
    AddDetail(({"pueblo","villa","Narad"}),"Narad es el nombre de este pueblo. Es un pequeño "
        "pueblo situado en el suroeste del valle de Azzor, en su parte alta. Sus habitantes se "
        "dedican básicamente a la agricultura y a la destilación de bebida. La cerveza y el "
        "vino de esta zona son bien conocidos en la región.\n");
    SetIntNoise("Se escucha el ajetreo normal de un pueblo.\n");
    SetIntSmell("No huele a nada en especial.\n");
    SetLocate("villa de Narad");
    SetIndoors(0);
    AddExit("oeste",NARAD("calle01"));
    AddExit("este",NARAD("calle03"));
    AddExit("norte",NARAD("calle04"));
    AddExit("sur",NARAD("tienda"));
    AddDoor("sur","la puerta de la tienda",
        "Es una gruesa puerta de madera tosca, pero resistente.\n",
        ({"puerta","puerta norte","puerta de tienda","puerta de la tienda"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CANT_OPEN_MSG:({"Intentas abrir la puerta, y al no poder, la miras y ves un "
                                 "cartel:\n'Cerramos de noche'\n",(:capitalize(TP->QueryName())+
                " trata de entrar en la tienda, pero se da cuenta de que cierra durante la "
                "noche.\n":),"Oyes a alguien intentando abrir una puerta.\n"}),
P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
}
