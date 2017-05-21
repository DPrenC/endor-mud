/*
DESCRIPCION  : Calle de Gaddaro
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/gaddaro/calle02.c
MODIFICACION : 
04-02-99 [Angor] Creacion
16-09-07 [Angor] Typos y retoques
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
    SetIntLong("La calle principal del pueblo alcanza aquí el extremo sur de la plaza, un "
        "espacio más o menos triangular encajado entre las casas. En medio de ella hay una "
        "pequeña fuente de piedra.\nUn agradable olor a comida emana desde la fonda 'el Tejón "
        "Rabioso' que se encuentra al este, demasiado tentador para tu pobre estómago...\nLa "
        "casa baja que queda al oeste parece ser el ayuntamiento.\n");
#include "geografia.ic"
#include "ambiente.ic"
    SetIntNoise("Oyes el ajetreo de la fonda.\n");
    SetIntSmell("Desde la fonda te llega un agradable olor a comida...\n");
    AddItem(OTRO("fuente_abrevadero"));
    AddExit("oeste",GADDARO("ayto"));
    AddExit("este",GADDARO("fonda"));
    AddExit("noroeste",GADDARO("calle04"));
    AddExit("norte",GADDARO("calle03"));
    AddExit("sur",GADDARO("calle01"));
    AddDoor("oeste", "la puerta principal del ayuntamiento",
        "Es la puerta principal del ayuntamiento de este pueblo.\n",
        ({"puerta", "puerta del ayuntamiento", "puerta oeste","puerta principal"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_CLOSE_TIME : ({ND_PREFALL, ND_FALL, ND_PRENIGHT, ND_NIGHT, ND_PREDAWN, ND_DAWN, ND_SUNRISE})]));
    SetSoundEnvironment(SND_AMBIENTES("agua_fuente"));
}
