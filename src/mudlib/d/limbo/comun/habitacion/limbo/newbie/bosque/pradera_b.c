/*
DESCRIPCION  : pradera (modelo b)
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/pradera_b.c
MODIFICACION : 06-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create()
{
    ::create();
    SetIntShort("la pradera en el parque");
    SetIntLong("A tu alrededor se extiende una inmensa pradera, más allá de la cuál se hallan varios pequeños bosques "
        "de robles. La hierba de la pradera se balancea al son que impone la suave brisa que llega del oeste.\n");
    AddDetail(({"hierba","tallos"}),"La hierba de la pradera tiene unos largos tallos de un color verde intenso.\n");
    AddDetail(({"pradera"}),"La pradera es una extensión de tierra en la que no crecen árboles sino hierba.\n");
    AddDetail(({"bosquecillo","bosque","pradera"}),"Puedes distinguir en el parque zonas donde se agrupan unos cuantos "
        "árboles y otras con claros donde crece la pradera.\n");
    AddDetail(({"parque","entrenamiento","novatos","parque de entrenamientos"}),"Estás en el parque de entrenamiento para "
        "novatos de la isla Limbo. Es una zona dispuesta por los dioses para que los recién llegados a este mundo puedan "
        "practicar con las armas y así ganar algo de experiencia y nivel antes de emprender aventuras en el resto del "
        "mundo.\n");
    SetIntNoise("Oyes a los pájaros trinar y al viento agitar las ramas de los árboles.\n");
    SetIntSmell("Huele a bosque.\n");
    SetLocate("parque de isla Limbo");
    SetIndoors(0);
}
