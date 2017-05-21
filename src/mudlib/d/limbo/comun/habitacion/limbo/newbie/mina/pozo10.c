/*
DESCRIPCION  : parte baja de un pozo en la mina
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/mina/pozo10.c
MODIFICACION : 05-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create()
{
    ::create();
    SetIntShort("la parte baja de un pozo de la mina");
    SetIntLong("Sobre tu cabeza se alza un agujero oscuro cuya altura no adivinas. Estás en lo que parece ser la parte "
        "baja de uno de los pozos de esta mina. En la pared del pozo hay fijada una escalera que permite ascender por él. "
        "A partir de aquí parte también una galería de este nivel de la mina.\n");
    AddDetail(({"pozo"}), QueryIntLong());
    AddDetail(({"escalera"}),"Una larga escalera de madera está fijada firmemente a la pared del pozo. Permite bajar y "
        "subir por él.\n");
    SetIntNoise("Oyes el eco de tus pasos y el goteo del agua.\n");
    SetIntSmell("Huele a tierra mojada.\n");
    SetLocate("mina de isla Limbo");
    SetIndoors(1);
    SetIntBright(0);
    AddExit("este",MINA("cruce02"));
    AddExit("arriba",MINA("pozo11"));
    AddItem(PNJ("murcielago"), REFRESH_DESTRUCT, 1);
}
