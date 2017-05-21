/*
DESCRIPCION  : parte media de un pozo en la mina (modelo)
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/pozo_b.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create()
{
    ::create();
    SetIntShort("la parte media de un pozo de la mina");
    SetIntLong("Te hallas en una escalera que recorre el interior de uno de los pozos de esta mina. El ambiente es húmedo "
        "y polvoriento. Observas cómo por las paredes verticales del pozo resbalan y gotean unos delgados hilillos de agua "
        "buscando el fondo del pozo.\n");
    AddDetail(({"pozo"}), QueryIntLong());
    AddDetail(({"escalera"}),"Una larga escalera de madera está fijada firmemente a la pared del pozo. Permite bajar y "
        "subir por él.\n");
    AddDetail(({"agua","hilillos"}),"El agua subterránea se filtra en el interior de la mina, produciendo incontables "
        "goteras en las galerías. Este agua acaba llegando a los pozos de la mina y deslizándose por ellos hacia los "
        "niveles inferiores.\n");
    SetIntNoise("Oyes el eco de tus pasos y el goteo del agua.\n");
    SetIntSmell("Huele a tierra mojada.\n");
    SetLocate("mina de isla Limbo");
    SetIndoors(1);
    SetIntBright(0);
}
