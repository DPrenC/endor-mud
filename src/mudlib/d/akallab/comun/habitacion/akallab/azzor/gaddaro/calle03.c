/*
DESCRIPCION  : Calle de Gaddaro
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/gaddaro/calle03.c
MODIFICACION : 04-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
#include <sounds.h>
#include <properties.h>
#include <door.h>
#include <scheduler.h>
inherit ROOM;

create()
{
    ::create();
    SetIntShort("la calle del pueblo de Gaddaro");
    SetIntLong("Estás en una de las esquinas de la plaza del pueblo de Gaddaro. El chorro de "
        "la fuente que observas en medio de la plaza canta alegremente. Por lo expuesto en su "
        "fachada, dirías que la casa que ves al norte es una tienda. El camino que queda al "
        "este parece alejarse del pueblo.\n");
#include "geografia.ic"
#include "ambiente.ic"
    SetIntNoise("La fuente borbotea alegremente.\n");
    SetIntSmell("No huele a nada en especial.\n");
    SetLocate("pueblo de Gaddaro");
    SetIndoors(0);
    AddItem(OTRO("fuente_abrevadero"));
    AddExit("norte",GADDARO("tienda"));
    AddExit("sur",GADDARO("calle02"));
    AddExit("oeste",GADDARO("calle04"));
    AddExit("este",GADDARO("calle06"));
    AddDoor("norte","la puerta de la tienda",
        "Es una gruesa puerta de madera tosca, pero resistente.\n",
        ({"puerta","puerta sur","puerta de tienda","puerta de la tienda"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CANT_OPEN_MSG:({"Intentas abrir la puerta, y al no poder, la miras y ves un "
                                 "cartel:\n'Cerrado\nVuelva por la mañana'\n",(:capitalize(TP->QueryName())+
                " trata de entrar en la tienda, pero se da cuenta de que cierra durante la "
                "noche.\n":),"Oyes a alguien intentando abrir una puerta.\n"}),
P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    SetSoundEnvironment(SND_AMBIENTES("agua_fuente"));
}
