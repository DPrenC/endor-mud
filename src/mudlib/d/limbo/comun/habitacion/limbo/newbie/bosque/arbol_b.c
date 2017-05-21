/*
DESCRIPCION  : junto al pie de un arbol (modelo b)
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/arbol_b.c
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
    SetIntLong("Frente a ti se alza un gran roble cuyas ramas se mecen al ritmo de la brisa que sopla suavemente desde "
        "la costa oeste de la isla. El árbol ha crecido junto a otros de su misma especie formando así un pequeño bosque. "
        "La hojarasca del suelo cruje a cada paso que das.\n");
    AddDetail(({"hojarasca"}),"El suelo esta cubierto por hojas resecas que hace tiempo cayeron de los árboles.\n");
    AddDetail(({"arbol","Arbol","roble"}),"El árbol junto al que te encuentras es un roble adulto. Calculas que tendrá "
        "como unos tres o quizá cuatro metros de altura y parece bastante robusto.\n");
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
