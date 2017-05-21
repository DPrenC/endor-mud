/*
DESCRIPCION  : parte baja inundada de un pozo en la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/pozo_c.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

#define NOMBRE (capitalize(TP->QueryName()))

int bajar()
{
    write("La idea de bajar no acaba de convencerte demasiado.\nMetes un pie en el agua y notas que esta muy fría, casi "
        "congelada. Sumergido en un agua tan fría nadie dura vivo mas de unos minutos... Decides no arriesgarte.\n");
    say(  NOMBRE+" se acerca al borde del agua y mete el pie en ella, para sacarlo a toda velocidad. El agua debe estar "
        "muy fría, por lo que "+NOMBRE+" decide no meterse en ella.\n",TP);
    return 1;
}

create()
{
    ::create();
    SetIntShort("la parte baja inundada de un pozo de la mina");
    SetIntLong("La escalera sigue descendiendo por la pared del pozo hasta llegar a un punto en el que se sumerge en el "
        "agua que lo inunda. No sabrías decir que profundidad tiene el pozo debido a lo oscura que está el agua: tal vez "
        "acabe unos metros más abajo o tal vez permita acceder a niveles inferiores de la mina que ahora están inundados... "
        "El agua está muy fría.\n");
    AddDetail(({"pozo","final"}), QueryIntLong());
    AddDetail(({"escalera"}),"Una larga escalera de madera está fijada firmemente a la pared del pozo. Permite bajar y "
        "subir por él.\n");
    AddDetail(({"agua"}),"El agua subterránea se filtra en el interior de la mina, produciendo incontables goteras en las "
        "galerías. Este agua acaba llegando a los pozos de la mina y deslizándose por ellos hacia los niveles inferiores. "
        "A estas profundidades, la roca es bastante maciza, por lo que el agua se acumula aquí hasta que poco a poco se "
        "filtra entre las rocas.\n");
    SetIntNoise("Oyes el eco de tus pasos y el goteo del agua.\n");
    SetIntSmell("Huele a tierra mojada.\n");
    SetLocate("mina de isla Limbo");
    SetIndoors(1);
    SetIntBright(0);
    AddExit("arriba",MINA("pozo07"));
    AddExit("abajo",SF(bajar));
    AddItem(OTRO("cristal"), REFRESH_DESTRUCT, 1);
}
