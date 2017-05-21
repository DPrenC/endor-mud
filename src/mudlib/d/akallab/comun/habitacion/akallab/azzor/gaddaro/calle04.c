/*
DESCRIPCION  : Calle de Gaddaro
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/gaddaro/calle04.c
MODIFICACION : 04-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
#include <properties.h>
#include <door.h>
#include <nightday.h>
#include <sounds.h>
inherit ROOM;

create()
{
    ::create();
    SetIntShort("la calle del pueblo de Gaddaro");
    SetIntLong("La plaza del pueblo se estrecha aquí hasta convertirse en el camino que avanza "
        "hacia el oeste. Ráfagas de viento han hecho que el chorro de agua de la fuente que "
        "hay en el centro, moje parte del suelo de tierra de este lado de la plaza.\n");
    AddDetail(({"suelo","barro"}),"Está mojado por culpa de la fuente. Lleva cuidado si no "
        "quieres llenarte de barro.\n");
#include "geografia.ic"
#include "ambiente.ic"
    SetIntNoise("La fuente borbotea alegremente.\n");
    SetIntSmell("No huele a nada en especial.\n");
    SetLocate("pueblo de Gaddaro");
    SetIndoors(0);
    AddItem(OTRO("fuente_abrevadero"));
    AddExit("sudeste",GADDARO("calle02"));
    AddExit("este",GADDARO("calle03"));
    AddExit("oeste",GADDARO("calle05"));
    AddExit("norte",GADDARO("casa02"));
    AddExit("sur",GADDARO("ayto"));
    AddDoor("sur", "la puerta trasera del ayuntamiento",
        "Es la puerta trasera del ayuntamiento del pueblo.\nProbablemente es la que utilizan "
            "los pueblerinos para ser atendidos en días corrientes.\n",
        ({"puerta", "puerta del ayuntamiento","puerta sur","puerta trasera"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_CLOSE_TIME : ({ND_PREFALL, ND_FALL, ND_PRENIGHT, ND_NIGHT, ND_PREDAWN, ND_DAWN, ND_SUNRISE})]));
    SetSoundEnvironment(SND_AMBIENTES("agua_fuente"));
}
