/*
DESCRIPCION  : en la copa de un arbol (modelo a)
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/arbol_b.c
MODIFICACION : 07-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create()
{
    ::create();
    SetIntShort("la copa de un árbol");
    SetIntLong("Te encuentras en la copa de uno de los robles del parque. Desde aquí se observa mejor la zona del parque: "
        "bosquecillos de robles se alternan con claros en los que se extiende la pradera. A esta altura las ramas del "
        "árbol aún son lo bastante resistentes como para aguantar tu peso.\n");
    AddDetail(({"ramas"}),"A la altura a la que estás, las ramas son razonablemente gruesas como para soportar tu peso, "
        "aunque no te acaba de gustar cómo se doblan...\n");
    AddDetail(({"bosquecillo","bosque","pradera"}),"Puedes distinguir en el parque zonas donde se agrupan unos cuantos "
        "árboles y otras con claros donde crece la pradera.\n");
    AddDetail(({"parque","entrenamiento","novatos","parque de entrenamiento"}),"Estás en el parque de entrenamiento para "
        "novatos de la isla Limbo. Es una zona dispuesta por los dioses para que los recién llegados a este mundo puedan "
        "practicar con las armas y así ganar algo de experiencia y nivel antes de emprender aventuras en el resto del "
        "mundo.\n");
    SetIntNoise("Oyes a los pájaros trinar y al viento agitar las ramas de los árboles.\n");
    SetIntSmell("Huele a bosque.\n");
    SetLocate("parque de isla Limbo");
    SetIndoors(0);
}
