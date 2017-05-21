/*
DESCRIPCION  : junto al pie de un arbol (modelo a)
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/arbolo_a.c
MODIFICACION : 06-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create()
{
    ::create();
    SetPreIntShort("junto a");
    SetIntShort("el pie de un árbol");
    SetIntLong("Te encuentras junto al pie de un árbol en un bosquecillo del parque. La brisa sopla suavemente desde el "
        "oeste agitando las ramas de los árboles. El árbol junto al que te encuentras es lo suficientemente robusto como "
        "para poder subir a su copa.\n");
    AddDetail(({"arbol","árbol"}),"El árbol junto al que te encuentras es un roble adulto. Calculas que tendrá como unos "
        "tres o quizá cuatro metros de altura y parece bastante robusto.\n");
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
